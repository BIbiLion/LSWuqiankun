#include "DisplayWidget.h"
#include "ui_DisplayWidget.h"

#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QMouseEvent>

DisplayWidget::DisplayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWidget)
{
    ui->setupUi(this);
    m_brushCell = NULL;

    setPen("#FF0000");
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}

void DisplayWidget::setPicture(const QString& imagePath)
{
    m_image = QImage(imagePath);

    setFixedWidth(m_image.width() < 60 ? 60 : m_image.width());
    setFixedHeight(m_image.height() < 60 ? 60 : m_image.height());

    QApplication::processEvents();

    while (!m_commands.isEmpty())
    {
        undo();
    }

    QApplication::processEvents();

    update();
}

void DisplayWidget::saveImage(const QString& imagePath)
{
    /*
    QImage image;
    image.scaled(size());
    image.save(imagePath);
    */

    QString format = imagePath.split(".").last();

    bool res = grab().toImage().save(imagePath, format.toStdString().c_str());
    qDebug() << __FUNCTION__ << " " << res << " " << format;
}

void DisplayWidget::paintEvent(QPaintEvent* pevent)
{   
    Q_UNUSED(pevent);

    struct PaintFunc
    {
        void paintBrushCell(BRUSH_CELL& brushCell, QPainter* painter)
        {
            painter->save();
            QPainterPath painterPath;
            QPainterPathStroker stroker;
            stroker.setWidth(brushCell.size);

            painter->setBrush(QColor(brushCell.color));
            painter->setPen(Qt::NoPen);

            for (int i = 0; i < brushCell.path().size(); ++i)
            {
                if (i == 0)
                {
                    painterPath.moveTo(brushCell.path()[i]);
                }
                else
                {
                    painterPath.lineTo(brushCell.path()[i]);
                }
            }
            QPainterPath pPath = stroker.createStroke(painterPath);
            painter->drawPath(pPath.simplified());
            painter->restore();
        }
    };

    PaintFunc func;
    QPainter painter(this);
    painter.drawImage(0, 0, m_image);

    QMutexLocker locker(&m_locker);
    for (int i = 0; i < m_commands.size(); ++i)
    {
        func.paintBrushCell(*m_commands[i], &painter);
    }
}

void DisplayWidget::setPen(const QString& penColor)
{
    setProperty("penColor", penColor);
}

void DisplayWidget::mousePressEvent(QMouseEvent* pevent)
{
    if (pevent->button() == Qt::LeftButton)
    {
        setProperty("isPressed", true);
        qDebug() << __FUNCTION__;

        if (m_brushCell == NULL)
        {
            m_brushCell = new BRUSH_CELL;
            m_brushCell->color = property("penColor").toString();
            m_brushCell->size = 5;

            if (!m_commands.contains(m_brushCell))
            {
                m_commands.append(m_brushCell);
            }

            m_brushCell->addPath(pevent->pos());
        }
    }

    update();
}

void DisplayWidget::mouseReleaseEvent(QMouseEvent* pevent)
{
    QMutexLocker locker(&m_locker);
    if (pevent->button() == Qt::LeftButton)
    {
        setProperty("isPressed", false);
        qDebug() << __FUNCTION__;

        if (m_brushCell != NULL)
        {
            if (m_brushCell->path().size() == 0)
            {
                m_commands.removeOne(m_brushCell);
            }
        }
        m_brushCell = NULL;
    }
}

void DisplayWidget::mouseMoveEvent(QMouseEvent* pevent)
{
    QMutexLocker locker(&m_locker);
    if (property("isPressed").toBool())
    {
        m_brushCell->addPath(pevent->pos());
        update();
    }
}

void DisplayWidget::undo()
{
    QMutexLocker locker(&m_locker);
    qDebug() << "in key";
    if (property("isPressed").toBool())
    {
        return;
    }

    qDebug() << "in undo";

    if (!m_commands.isEmpty())
    {
        delete m_commands.takeLast();
        qDebug() << "undo";
    }

    update();


}

