#include "mainwindow.h"
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QSettings>
#include <QDateTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    connect(&timer, SIGNAL(timeout()), SLOT(onTimer()));

    result = FMOD_System_Create(&system);
    result = FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, 0);
    sound = 0;
    channel = 0;
    wav.resize(2048);

    ploter->setAdjustVal(0.5);
    ploter->outPut();
    ploterAll->Pen = QPen(QBrush(QColor(89, 172, 255)), 1);
    loadIni(true);
}

MainWindow::~MainWindow()
{
    on_actionStop_triggered();
    loadIni(false);
}

void MainWindow::loadIni(bool isLoad)
{
    QSettings setter("./config.ini", QSettings::IniFormat);
    QStringList list;
    if (isLoad)
    {
        list = setter.value("sound/files", list).toStringList();
        for (int i = 0 ; i < list.size(); i++)
        {
            QStringList tmp = list[i].split(";");
            QListWidgetItem *item = new QListWidgetItem(tmp[0]);
            item->setData(Qt::UserRole, tmp[1]);
            lwList->addItem(item);
        }
    }
    else
    {
        for (int i = 0; i < lwList->count(); i++)
        {
            QListWidgetItem *item = lwList->item(i);
            list << item->text() + ";" + item->data(Qt::UserRole).toString();
            setter.setValue("sound/files", list);
        }
    }
}

void MainWindow::onTimer()
{
    float *dat = new float[16384];
    FMOD_System_GetWaveData(system, dat, 16384, 0);
    //FMOD_System_GetSpectrum(system, dat, 8192, 1, FMOD_DSP_FFT_WINDOW_RECT); 频谱
    for (int i = 0, n = 0; i < 16384; i+= 8, n++)
        wav[n] = dat[i];
    ploter->outPut(wav);
    delete [] dat;
    if (channel)
    {
        uint pos;
        FMOD_Channel_GetPosition(channel, &pos, FMOD_TIMEUNIT_MS);
        slTime->setValue(pos);
        pos /= 1000;
        lbCurTime->setText(QString().sprintf(" %02d:%02d", pos/60, pos%60));
        FMOD_BOOL isPlay;
        FMOD_Channel_IsPlaying(channel, &isPlay);
        if (!isPlay)
        {
            timer.stop();
            if (lwList->currentRow() < lwList->count() - 1)
            {
                lwList->setCurrentRow(lwList->currentRow() + 1);
                on_actionPlay_triggered();
            }
            else
                on_actionStop_triggered();
        }
    }
}

void MainWindow::plotAllWav(char *fileName)//使用fmod从音乐文件中获得音频图频 采样点
{
    FMOD_System_CreateSound(system, fileName, FMOD_2D | FMOD_SOFTWARE | FMOD_CREATESAMPLE, 0, &sound);
    uint bytes, len1, len2;
    void *ptr1, *ptr2;
    FMOD_Sound_GetLength(sound, &bytes, FMOD_TIMEUNIT_PCMBYTES);
    FMOD_Sound_Lock(sound, 0, bytes, &ptr1, &ptr2, &len1, &len2);

    bytes /= 2;
    int step= 1, len= bytes;
    if (bytes > 10000)
    {
        len = 10000;
        step= (int)(bytes / len);
    }
    QVector<float>wavAll(10000);
    short* ps = (short*)ptr1;
    for (int i= 0, n = 0; n< len; i+= step, n++)
        wavAll[n] = ps[i];
    FMOD_Sound_Unlock(sound, ptr1, ptr2, len1, len2);
    FMOD_Sound_Release(sound);
    ploterAll->outPut(wavAll);//画整个音频文件的 音频图谱
}

void MainWindow::on_actionAdd_triggered()//add sounds list
{
    QString strPath = QFileDialog::getExistingDirectory(0, "请选择歌曲路径");
    if (strPath.isNull() || strPath.isEmpty())
        return;
    QDir dir(strPath);
    QStringList list;
    list << "*.mp3" << "*.wma" << "*.ape" << "*.flac" << "*aac" << "*.amr" << "*.ogg" << "*.wav";
    QFileInfoList listFiles = dir.entryInfoList(list, QDir::Files, QDir::Name);
    int len = listFiles.size();
    if (len <= 0)
        return;
    for (int i = 0; i < len; i++)
    {
        QListWidgetItem *item = new QListWidgetItem(listFiles[i].fileName().split(".")[0]);
        item->setData(Qt::UserRole, listFiles[i].absoluteFilePath());
        lwList->addItem(item);
    }
}

void MainWindow::on_actionMinus_triggered()//delete sound
{
    int row = lwList->currentRow();
    if (row == -1)
        return;
    QListWidgetItem *item = lwList->item(row);
    lwList->removeItemWidget(item);
    delete item;
}

void MainWindow::on_actionClear_triggered()
{
    lwList->clear();
}

void MainWindow::on_actionList_triggered()//hide show sounds listWidget
{
    lwList->setVisible(!lwList->isVisible());
}

void MainWindow::on_actionPlay_triggered()//play 演唱
{
    int row = lwList->currentRow();
    if (row == -1)
        return;
    on_actionStop_triggered();
    QString strFile = lwList->currentItem()->data(Qt::UserRole).toString();

    if (!QFile::exists(strFile))
    {
        if (row >= lwList->count() - 1)
            return;
        lwList->setCurrentRow(row + 1);
        on_actionPlay_triggered();
    }
    plotAllWav(strFile.toLocal8Bit().data());


    //fmod播放音频
    FMOD_System_CreateSound(system, strFile.toLocal8Bit().data(), FMOD_SOFTWARE | FMOD_CREATESAMPLE, 0, &sound);
    FMOD_Sound_SetMode(sound, FMOD_LOOP_OFF);
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, false, &channel);
    uint length;
    FMOD_Sound_GetLength(sound, &length, FMOD_TIMEUNIT_MS);
    slTime->setMaximum(length);
    length /= 1000;
    lbTotalTime->setText(QString().sprintf("%02d:%02d ", length/60, length%60));
    FMOD_System_Update(system);
    timer.start(300);
}

void MainWindow::on_actionPause_triggered()//暂停 播放
{
    if (channel)
    {
        FMOD_BOOL pause;
        FMOD_Channel_GetPaused(channel, &pause);
        FMOD_Channel_SetPaused(channel, !pause);
        actionPause->setChecked(!pause);
        (!pause) ? timer.stop() : timer.start(300);
    }
}

void MainWindow::on_actionStop_triggered()
{
    if (channel)
    {
        actionPause->setChecked(false);
        FMOD_Channel_Stop(channel);
        channel = NULL;
        timer.stop();
        lbCurTime->setText(" 00:00");
        lbTotalTime->setText("00:00 ");
        slTime->setValue(0);
        ploter->outPut();
    }
}

void MainWindow::on_slTime_sliderMoved(int position)
{
    if (channel) FMOD_Channel_SetPosition(channel, position, FMOD_TIMEUNIT_MS);
}

void MainWindow::on_lwList_doubleClicked(const QModelIndex &index)
{
    on_actionPlay_triggered();
}
