#include "cdefinechart.h"
#include<QDebug>

CDefineChart::CDefineChart(QWidget *parent) :
    QWidget(parent)
{
    m_piechart=NULL;
    m_xychart=NULL;

    // The data for the pie chart
    //double data[]= {25, 18, 15, 12, 8, 30, 35};
    const char *m_label[]={"项目1", "项目2", "项目3", "项目4", "项目5","项目6", "项目7","项目8"};
    for(int i=0;i<DATA_NUM;i++)
    {
        data[i]=rand()%200;
        //labels[i]=(QString("项目%0").arg(i)).toLatin1().data();
        //QString  str=QString("item%0").arg(i+1);

        //QByteArray ba = str.toLatin1();
        //qDebug()<<str.toLatin1().data();

        labels[i]=m_label[i];
    }
}

BaseChart * CDefineChart::showHistogram()
{

    /*
    // The data for the bar chart
    double data[] = {450, 560, 630, 800, 1100, 1350, 1600, 1950, 2300, 700};

    // The labels for the bar chart
    const char *labels[] = {"项目1", "项目2", "1998", "1999", "2000", "2001", "2002",
        "2003", "2004", "2005"};
    */

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

    //c->addTitle("柱形图统计表","timesbi.ttf",18)->setMargin(0, 0,
      //  8, 8);

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

    m_xychart->makeChart();

    return m_xychart;
}

BaseChart * CDefineChart::showPieChart()
{
    //pie chart
    /*
    // The data for the pie chart
    double data[] = {25, 18, 15, 12, 8, 30, 35};

    // The labels for the pie chart
    const char *labels[] = {"项目1", "项目2", "项目3", "项目4", "项目5",
        "项目6", "项目7"};
    */

    // Create a PieChart object of size 360 x 300 pixels
    m_piechart = new PieChart(860, 600);

    m_piechart->setDefaultFonts("mingliu.ttc", "mingliu.ttc Bold");
    // Set the center of the pie at (180, 140) and the radius to 100 pixels
    m_piechart->setPieSize(300, 260, 230);

    // Add a title to the pie chart    
    m_piechart->addTitle("饼状图统计图","mingliu.ttc Bold",18)->setMargin(0,0,8,8);

    // Draw the pie in 3D
    m_piechart->set3D();


    // add a legend box where the top left corner is at (330, 50)
    m_piechart->addLegend(650, 60);


    // Set the pie data and the pie labels
    m_piechart->setData(DoubleArray(data, sizeof(data)/sizeof(data[0])), StringArray(labels,
        sizeof(labels)/sizeof(labels[0])));

    // Explode the 1st sector (index = 0)
    //c->setExplode(1);

    // Output the chart
    //c->makeChart("threedpie.png");

    m_piechart->makeChart();

    return m_piechart;
}

BaseChart * CDefineChart::showLineChart()
{

    // The data for the line chart
        double data1[] = {30, 28, 40, 55, 75, 68, 54, 60, 50, 62, 75, 65, 75, 91, 60, 55,
            53, 35, 50, 66, 56, 48, 52, 65, 62};

        // The labels for the line chart
        const char *labels1[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
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
        m_linechart->addLineLayer(DoubleArray(data1, sizeof(data1)/sizeof(data1[0])), 0x6666ff
            )->set3D();

        // Set the labels on the x axis.
        m_linechart->xAxis()->setLabels(StringArray(labels1, sizeof(labels1)/sizeof(labels1[0])));

        // Display 1 out of 3 labels on the x-axis.
        m_linechart->xAxis()->setLabelStep(3);

        m_linechart->makeChart();

        return m_linechart;

}

CDefineChart::~CDefineChart()
{
    if(m_xychart)
    {
        delete m_xychart;
        m_xychart=NULL;
    }

    if(m_piechart)
    {
        delete m_piechart;
        m_piechart=NULL;
    }

    if(m_linechart)
    {
        delete m_linechart;
        m_linechart=NULL;
    }
}
