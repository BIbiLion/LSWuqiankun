#include "chistogram.h"
#include<QVBoxLayout>
#include<QPushButton>
#include<QMessageBox>
Chistogram::Chistogram(QWidget *parent) :
    QWidget(parent)
{

   QVBoxLayout *m_vLayout=new QVBoxLayout;
   QHBoxLayout *m_hLayout=new QHBoxLayout;


   QPushButton *m_pushButton=new QPushButton;
   m_pushButton->setText(tr("截图"));
   //m_pushButton->setGeometry(0,0,80,40);
   //m_pushButton->setSizePolicy();
   connect(m_pushButton,SIGNAL(clicked()),this,SLOT(saveImage()));


   m_hLayout->addWidget(m_pushButton);
   m_hLayout->addStretch();

   QChartViewer *viewer=new QChartViewer(this);


   m_vLayout->addLayout(m_hLayout);
   m_vLayout->addWidget(viewer);
   m_vLayout->addStretch();

   this->setLayout(m_vLayout);

   // The data for the bar chart
   double data[] = {450, 560, 630, 800, 1100, 1350, 1600, 1950, 2300, 700};

   // The labels for the bar chart
   const char *labels[] = {"项目1", "项目2", "项目3", "项目4", "项目5", "项目6", "项目7",
       "项目8", "项目9", "项目10"};


   // Create a XYChart object of size 600 x 380 pixels. Set background color to
   // brushed silver, with a 2 pixel 3D border. Use rounded corners of 20 pixels
   // radius.
   m_xychart = new XYChart(700, 480);
   //XYChart *c = new XYChart(600, 380, Chart::brushedSilverColor(),Chart::Transparent, 2);

   // Add a title to the chart using 18pts Times Bold Italic font. Set top/bottom
   // margins to 8 pixels.
   //c->setDefaultFonts("simsun.ttc", "simsun.ttc", "simsun.ttc", "simsun.ttc");
   m_xychart->setDefaultFonts("mingliu.ttc", "mingliu.ttc Bold");
   //QByteArray str=QString("柱形图统计表").toUtf8();
   m_xychart->addTitle("柱形图统计表","mingliu.ttc Bold",18)->setMargin(0,0,8,8);


   // Set the plotarea at (70, 55) and of size 460 x 280 pixels. Use transparent
   // border and black grid lines. Use rounded frame with radius of 20 pixels.
   m_xychart->setPlotArea(70, 55, 560, 380, -1, -1, Chart::Transparent, 0x000000);
   m_xychart->setRoundedFrame(0xffffff, 20);

   // Add a multi-color bar chart layer using the supplied data. Set cylinder bar
   // shape.
   m_xychart->addBarLayer(DoubleArray(data, sizeof(data)/sizeof(data[0])), IntArray(0, 0)
       )->setBarShape(Chart::CircleShape);

   // Set the labels on the x axis.
   m_xychart->xAxis()->setLabels(StringArray(labels, sizeof(labels)/sizeof(labels[0])));
   //c->xAxis()->setLabels(labels);

   // Show the same scale on the left and right y-axes
   m_xychart->syncYAxis();

   // Set the left y-axis and right y-axis title using 10pt Arial Bold font
   //c->yAxis()->setTitle("USD (millions)", "arialbd.ttf", 10);
   //c->yAxis2()->setTitle("USD (millions)", "arialbd.ttf", 10);

   // Set y-axes to transparent
   m_xychart->yAxis()->setColors(Chart::Transparent);
   m_xychart->yAxis2()->setColors(Chart::Transparent);

   // Disable ticks on the x-axis by setting the tick color to transparent
   m_xychart->xAxis()->setTickColor(Chart::Transparent);

   // Set the label styles of all axes to 8pt Arial Bold font
   //c->xAxis()->setLabelStyle("arialbd.ttf", 8);
   //c->yAxis()->setLabelStyle("arialbd.ttf", 8);
   //c->yAxis2()->setLabelStyle("arialbd.ttf", 8);

   viewer->setChart(m_xychart);

   // Include tool tip for the chart
   viewer->setImageMap(
       m_xychart->getHTMLImageMap("", "", "title='{xLabel}: {value}'"));


   //
   // Show the viewer
   //

   viewer->show();

}
void Chistogram::setImagePath(QString savepath)
{
    m_imgsavePath=savepath;
}

void Chistogram::saveImage()
{
    if(!m_imgsavePath.isEmpty())
    {
        m_imgsavePath+=QString("/histogramchart.png");
    }

    m_xychart->makeChart(m_imgsavePath.toStdString().c_str());

    QMessageBox w;
    w.setWindowTitle(tr("提示"));
    w.setText(tr("截图成功"));
    w.exec();
}

Chistogram::~Chistogram()
{
    delete m_xychart;
    m_xychart=NULL;
}

