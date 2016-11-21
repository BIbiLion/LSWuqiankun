#include "clinechart.h"
#include<QVBoxLayout>
#include<QPushButton>
#include<QMessageBox>
Clinechart::Clinechart(QWidget *parent) :
    QWidget(parent)
{

    QVBoxLayout *m_vLayout=new QVBoxLayout;
    QHBoxLayout *m_hLayout=new QHBoxLayout;

    QPushButton *m_pushButton=new QPushButton;
    m_pushButton->setText(tr("截图"));

    connect(m_pushButton,SIGNAL(clicked()),this,SLOT(saveImage()));

    m_hLayout->addWidget(m_pushButton);
    m_hLayout->addStretch();

    QChartViewer *viewer=new QChartViewer(this);


    m_vLayout->addLayout(m_hLayout);
    m_vLayout->addWidget(viewer);
    m_vLayout->addStretch();
    this->setLayout(m_vLayout);

    // The data for the line chart
    double data[] = {30, 28, 40, 55, 75, 68, 54, 60, 50, 62, 75, 65, 75, 91, 60, 55,
        53, 35, 50, 66, 56, 48, 52, 65, 62};

    // The labels for the line chart
    const char *labels[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23",
        "24"};

    // Create a XYChart object of size 300 x 280 pixels
    m_linechart = new XYChart(600, 580);
    m_linechart->setDefaultFonts("mingliu.ttc", "mingliu.ttc Bold");
    // Set the plotarea at (45, 30) and of size 200 x 200 pixels
    m_linechart->setPlotArea(45, 80, 500, 400);

    // Add a title to the chart using 12 pts Arial Bold Italic font
    m_linechart->addTitle("折线统计图", "mingliu.ttc Bold", 18)->setMargin(0,0,8,8);

    // Add a title to the y axis
    //m_linechart->yAxis()->setTitle("MBytes");

    // Add a title to the x axis
    //m_linechart->xAxis()->setTitle("June 12, 2001");

    // Add a blue (0x6666ff) 3D line chart layer using the give data
    m_linechart->addLineLayer(DoubleArray(data, sizeof(data)/sizeof(data[0])), 0x6666ff
        )->set3D();

    // Set the labels on the x axis.
    m_linechart->xAxis()->setLabels(StringArray(labels, sizeof(labels)/sizeof(labels[0])));

    // Display 1 out of 3 labels on the x-axis.
    m_linechart->xAxis()->setLabelStep(3);    

    viewer->setChart(m_linechart);

    // Include tool tip for the chart
    viewer->setImageMap(m_linechart->getHTMLImageMap("", "", "title='{xLabel}: {value}'"));

    //
    // Show the viewer
    //

    viewer->show();
}
void Clinechart::setImagePath(QString savepath)
{
    m_imgsavePath=savepath;
}

void Clinechart::saveImage()
{
    if(!m_imgsavePath.isEmpty())
    {
        m_imgsavePath+=QString("/linechart.png");
    }

    m_linechart->makeChart(m_imgsavePath.toStdString().c_str());

    QMessageBox w;
    w.setWindowTitle(tr("提示"));
    w.setText(tr("截图成功"));
    w.exec();
}

Clinechart::~Clinechart()
{
    delete m_linechart;
    m_linechart=NULL;
}
