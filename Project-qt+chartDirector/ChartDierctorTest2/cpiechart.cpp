#include "cpiechart.h"
#include<QVBoxLayout>
#include<QPushButton>
#include<QMessageBox>

Cpiechart::Cpiechart(QWidget *parent) :
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
    //pie chart

    // The data for the pie chart
    double data[] = {450, 560, 630, 800, 1100, 1350, 1600, 1950, 2300, 700};

     double depth[]={1,5,8,10,14,16,27,38,40,50};
     DoubleArray _da(depth,10);
    // The labels for the bar chart
    const char *labels[] = {"项目1", "项目2", "项目3", "项目4", "项目5", "项目6", "项目7",
        "项目8", "项目9", "项目10"};

    // Create a PieChart object of size 360 x 300 pixels
    m_piechart = new PieChart(860, 600);

    m_piechart->setDefaultFonts("mingliu.ttc", "mingliu.ttc Bold");
    // Set the center of the pie at (180, 140) and the radius to 100 pixels
    m_piechart->setPieSize(300, 260, 230);

    // Add a title to the pie chart
    m_piechart->addTitle("饼状图统计表","mingliu.ttc Bold",18)->setMargin(0,0,8,8);

    // Draw the pie in 3D
    m_piechart->set3D(_da);

    // Use the side label layout method
    m_piechart ->setLabelLayout(Chart::CircleLayout);

    // add a legend box where the top left corner is at (330, 50)
    m_piechart->addLegend(650, 60);


    // Set the pie data and the pie labels
    m_piechart->setData(DoubleArray(data, sizeof(data)/sizeof(data[0])), StringArray(labels,
        sizeof(labels)/sizeof(labels[0])));

    // Explode the 1st sector (index = 0)
    m_piechart->setExplode(1);//浏览

    // Set donut center at (75, 65) and the outer radius to 50 pixels. Inner radius is computed
    // according donutWidth
       m_piechart->setDonutSize(300, 260, 50, 90);//空心


    // Add icons to the chart as a custom field
     //  m_piechart->addExtraField(StringArray(icons, (int)(sizeof(icons) / sizeof(icons[0]))));


    // Use rounded edge shading, with a 1 pixel white (FFFFFF) border
    //c->setSectorStyle(Chart::RoundedEdgeShading, 0xffffff, 1);

    // Output the chart
    viewer->setChart(m_piechart);
    m_piechart->makeChart("E:/piechart.png");

    // Include tool tip for the chart
    //viewer.setImageMap(
     //   c->getHTMLImageMap("", "", "title='{xLabel}: US${value}K'"));

    // In this sample project, we do not need to chart object any more, so we
    // delete it now.


    //
    // Show the viewer
    //

    viewer->show();

}
void Cpiechart::setImagePath(QString savepath)
{
    m_imgsavePath=savepath;
}

void Cpiechart::saveImage()
{
    if(!m_imgsavePath.isEmpty())
    {
        m_imgsavePath+=QString("/piechart.png");
    }

    m_piechart->makeChart(m_imgsavePath.toStdString().c_str());    

    QMessageBox w;
    w.setWindowTitle(tr("提示"));
    w.setText(tr("截图成功"));
    w.exec();
}

Cpiechart::~Cpiechart()
{
    delete m_piechart;
    m_piechart=NULL;
}
