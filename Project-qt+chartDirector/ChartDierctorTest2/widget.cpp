
//AngularMeter     角表  速度仪器

#include "widget.h"
#include "ui_widget.h"

#include<QFileDialog>
#include<QDebug>
#include<QProcess>

#include "realtimedemo.h"
#include <math.h>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_piechart=new Cpiechart;
    m_histogram=new Chistogram;
    m_linechart=new Clinechart;


    RealTimeDemo * realTimeDemo= new RealTimeDemo;

    ui->tabWidget->clear();
    ui->tabWidget->addTab(m_piechart,"饼图");
    ui->tabWidget->addTab(m_histogram,"柱状图");
    ui->tabWidget->addTab(m_linechart,"折线图");
    ui->tabWidget->addTab(addAngularMeter(),"角表");
    ui->tabWidget->addTab(addSurface(),"表面能量密度-3D");
    //  ui->tabWidget->addTab(realTimeDemo,"realTimeDemo");
    ui->tabWidget->addTab(addLineWithErrorSymbols(),"LineWithErrorSymbols");
    ui->tabWidget->addTab(addSwapXY(),"swapXY");

    ui->tabWidget->addTab(addLinearMeters(),"温度计");
    ui->tabWidget->addTab(addPyramid(),"金字塔");
    ui->tabWidget->addTab(addPolar(),"雷达图");
}



//Linear Meters 温度计
QWidget * Widget::addLinearMeters()
{
    // The value to display on the meter
    double value = 74.25;

    // Create an LinearMeter object of size 250 x 65 pixels with a very light grey (0xeeeeee)
    // background, and a rounded 3-pixel thick light grey (0xcccccc) border
    LinearMeter *m = new LinearMeter(250, 65, 0xeeeeee, 0xcccccc);
    m->setRoundedFrame(Chart::Transparent);
    //m->setThickFrame(3);

    // Set the scale region top-left corner at (14, 23), with size of 218 x 20 pixels. The scale
    // labels are located on the top (implies horizontal meter)
    m->setMeter(14, 23, 218, 20, Chart::Top);
    //  m->setMeter(28, 18, 20, 205);//竖直方向的温度计


    // Set meter scale from 0 - 100, with a tick every 10 units
    m->setScale(0, 100, 10);

    // Add a smooth color scale to the meter
    double smoothColorScale[] = {0, 0x6666ff, 25, 0x00bbbb, 50, 0x00ff00, 75, 0xffff00, 100,
                                 0xff0000};
    //      m->addColorScale(DoubleArray(smoothColorScale, (int)(sizeof(smoothColorScale) / sizeof(
    //          smoothColorScale[0]))));


    // Add a blue (0x0000cc) pointer at the specified value
    m->addPointer(value, 0x0000cc);

    // Output the chart
    m->makeChart("hlinearmeter.png");

    //free up resources
    // delete m;

    QWidget * _widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);
    _v->setChart(m);
    return _widget;
}


//Pyramid  金字塔
QWidget * Widget::addPyramid()
{
    // The data for the pyramid chart
    double data[] = {156, 123, 211, 179};

    // The labels for the pyramid chart
    const char *labels[] = {"Funds", "Bonds", "Stocks", "Cash"};

    // Create a PyramidChart object of size 360 x 360 pixels
    PyramidChart *c = new PyramidChart(800, 800);

    // Set the pyramid center at (180, 180), and width x height to 150 x 180 pixels
    // c->setPyramidSize(180, 180, 150, 300);//设置金字塔
    c->setConeSize(280, 180, 150, 300);//设置圆柱形

    // Set the funnel center at (200, 210), and width x height to 150 x 300 pixels
    //  c->setFunnelSize(200, 210, 150, 300);//设置漏斗形状

    // Set the pyramid data and labels
    c->setData(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), StringArray(labels, (int)(
                                                                                         sizeof(labels) / sizeof(labels[0]))));

    // Add labels at the center of the pyramid layers using Arial Bold font. The labels will have
    // two lines showing the layer name and percentage.
    c->setCenterLabel("{label}\n{percent}%", "arialbd.ttf");

    // Set the elevation to 30 degrees.rotate 70
    c->setViewAngle(30,70);

    // The colors for the pyramid layers
    int colors[] = {0x66aaee, 0xeebb22, 0xcccccc, 0xcc88ff};
    // Set the layer colors to the given colors
    c->setColors(Chart::DataColor, IntArray(colors, (int)(sizeof(colors) / sizeof(colors[0]))));


    // Leave 1% gaps between layers
    c->setLayerGap(0.01);

    // Add labels at the center of the pyramid layers using Arial Bold font. The labels will show
    // the percentage of the layers.
    c->setCenterLabel("{percent}%", "arialbd.ttf");
    // Add labels at the right side of the pyramid layers using Arial Bold font. The labels will
    // have two lines showing the layer name and value.
    c->setRightLabel("{label}\nUS$ {value}M", "arialbd.ttf");

    //addBox
    LegendBox *legendBox = c->addLegend(600, 60);
    legendBox->setBackground(0xeeeeee, 0x888888);
    legendBox->setRoundedCorners(10, 0, 10, 0);

    // Add labels at the center of the pyramid layers using Arial Bold font. The labels will show
    // the percentage of the layers.
    c->setCenterLabel("{percent}%", "arialbd.ttf");

    // Output the chart
    c->makeChart("simplepyramid.png");



    QWidget * _widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);
    _v->setChart(c);
    return _widget;
}


//雷达图 polar  radar
QWidget * Widget::addPolar()
{

    // The data for the chart
    double data[] = {90, 60, 65, 75, 40};

    // The labels for the chart
    const char *labels[] = {"Speed", "Reliability", "Comfort", "Safety", "Efficiency"};

    // Create a PolarChart object of size 450 x 350 pixels
    PolarChart *c = new PolarChart(450, 350);

    // Use 1 pixel width semi-transparent black (c0000000) lines as grid lines
    c->setGridColor(0xc0000000, 1, 0xc0000000, 1);

    // Set center of plot area at (225, 185) with radius 150 pixels
    c->setPlotArea(225, 185, 150);

    // Add an area layer to the polar chart
    c->addAreaLayer(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), 0x9999ff);


    //Add a red (0xcc6666)添加一个 区域的边框
    // line layer using the same data with 3 pixel line width to highlight the border of the area.
    c->addLineLayer(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), 0x6666cc
            )->setLineWidth(3);

    // Set the labels to the angular axis as spokes
    c->angularAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

    //        // Set radial axis from 0 - 100 with a tick every 20 units
    //            c->radialAxis()->setLinearScale(0, 100, 20);
    //            // Just show the radial axis as a grid line. Hide the axis labels by setting the label color to
    //                // Transparent
    //             c->radialAxis()->setColors(0xc0F0DD00);//, Chart::Transparent);


    // Set angular axis as 0 - 360, with a spoke every 30 units
       //c->angularAxis()->setLinearScale(0, 360, 30);


    // Output the chart
    c->makeChart("simpleradar.png");

    QWidget * _widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);
    _v->setChart(c);
    return _widget;
}


//3d  scatter 离散点  5.0版本没有 ThreeDScatterChart类
QWidget * Widget::addScatter()
{

    /*
    // The XYZ data for the 3D scatter chart as 3 random data series
        RanSeries *r = new RanSeries(3);
        DoubleArray xData = r->getSeries(20, 100, -10, 10);
        DoubleArray yData = r->getSeries(20, 100, -10, 10);
        DoubleArray zData = r->getSeries(20, 100, -10, 10);

        // Create a ThreeDScatterChart object of size 720 x 520 pixels
        ThreeDScatterChart *c = new ThreeDScatterChart(720, 520);

        // Add a title to the chart using 20 points Times New Roman Italic font
        c->addTitle("3D Scatter Chart (2)  ", "timesi.ttf", 20);

        // Set the center of the plot region at (350, 240), and set width x depth x height to 360 x 360
        // x 270 pixels
        c->setPlotRegion(350, 240, 360, 360, 270);

        // Set the elevation and rotation angles to 15 and 30 degrees
        c->setViewAngle(15, 30);

        // Add a scatter group to the chart using 13 pixels glass sphere symbols, in which the color
        // depends on the z value of the symbol
        ThreeDScatterGroup *g = c->addScatterGroup(xData, yData, zData, "", Chart::GlassSphere2Shape,
            13, Chart::SameAsMainColor);

        // Add grey (888888) drop lines to the symbols
        g->setDropLine(0x888888);

        // Add a color axis (the legend) in which the left center is anchored at (645, 220). Set the
        // length to 200 pixels and the labels on the right side. Use smooth gradient coloring.
        c->setColorAxis(645, 220, Chart::Left, 200, Chart::Right)->setColorGradient();

        // Set the x, y and z axis titles using 10 points Arial Bold font
        c->xAxis()->setTitle("X-Axis Place Holder", "arialbd.ttf", 10);
        c->yAxis()->setTitle("Y-Axis Place Holder", "arialbd.ttf", 10);
        c->zAxis()->setTitle("Z-Axis Place Holder", "arialbd.ttf", 10);

        // Output the chart
        c->makeChart("threedscatter2.png");

        //free up resources

*/
    QWidget * _widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);
   // _v->setChart(c);
    return _widget;
}

//Contour Color 热成像图  轮廓
QWidget * Widget::addContourColor()
{
    QWidget * _widget= new QWidget();
    //    QChartViewer * _v= new QChartViewer(_widget);
    //    _v->setChart(m);
    return _widget;
}


#include <QDebug>
#include <string.h>
//甘特图等 xy坐标轴交换的 bar
QWidget * Widget::addSwapXY()
{
    XYChart * _xychart= new XYChart(800,800);
    _xychart->swapXY(true);

    std::vector<int> _vec(10,1);
    _vec[2]=10;
    _vec[4]=100;

    int array[_vec.size()];
    memcpy(array,(void *)(&_vec[0]),sizeof(int)*_vec.size());

    for(int i=0;i< _vec.size();++i)
    {
        qDebug()<<"cccccccccccccccccc:"<< array[i];
    }



    QWidget * _widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);
    _v->setChart(_xychart);
    return _widget;
}


//只是一个demo,有内存泄露的
QWidget * Widget::addLineWithErrorSymbols()
{
    // The data with error information
    double data[] = {42, 49, 33, 38, 51, 46, 29, 41, 44, 57, 59, 52, 37, 34, 51, 56, 56, 60, 70, 76,
                     63, 67, 75, 64, 51};
    double errData[] = {5, 6, 5.1, 6.5, 6.6, 8, 5.4, 5.1, 4.6, 5.0, 5.2, 6.0, 4.9, 5.6, 4.8, 6.2,
                        7.4, 7.1, 6.0, 6.6, 7.1, 50.3, 5.5, 7.9, 6.1};

    // The labels for the chart
    const char *labels[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
                            "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24"};

    // Create a XYChart object of size 600 x 300 pixels, with a light grey (eeeeee) background,
    // black border, 1 pixel 3D border effect and rounded corners.
    XYChart *c = new XYChart(600, 300, 0xeeeeee, 0x000000, 1);
    c->setRoundedFrame(0xaafaaf);

    // Set the plotarea at (55, 55) and of size 520 x 195 pixels, with white (ffffff) background.
    // Set horizontal and vertical grid lines to grey (cccccc).
    c->setPlotArea(55, 55, 520, 195, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);

    // Add a title box to the chart using 15pt Times Bold Italic font. The title is in CDML and
    // includes embedded images for highlight. The text is on a light grey (dddddd) background, with
    // glass lighting effect.
    c->addTitle(
                "<*block,valign=absmiddle*><*img=star.png*><*img=star.png*> Molecular Temperature Control "
                "<*img=star.png*><*img=star.png*><*/*>", "timesbi.ttf", 15)->setBackground(0xdddddd, 0,
                                                                                           Chart::glassEffect());//增加玻璃效果

    // Add a title to the y axis
    c->yAxis()->setTitle("Temperature");

    // Add a title to the x axis using CMDL
    c->xAxis()->setTitle("<*block,valign=absmiddle*><*img=clock.png*>  Elapsed Time (hour)<*/*>");

    // Set the labels on the x axis.
    c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

    // Display 1 out of 3 labels on the x-axis. Show minor ticks for remaining labels.
    c->xAxis()->setLabelStep(3, 1);

    // Set the axes width to 2 pixels
    c->xAxis()->setWidth(2);
    c->yAxis()->setWidth(2);

    // Add a line layer to the chart
    LineLayer *lineLayer = c->addLineLayer();

    // Add a blue (0xff) data set to the line layer, with yellow (0xffff80) diamond symbols
    lineLayer->addDataSet(DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), 0x0000ff
            )->setDataSymbol(Chart::DiamondSymbol, 12, 0xffff80);

    // Set the line width to 2 pixels
    lineLayer->setLineWidth(2);

    // Add a box whisker layer to the chart. Use the upper and lower mark of the box whisker layer
    // to act as error zones. The upper and lower marks are computed using the ArrayMath object.
    BoxWhiskerLayer *errLayer = c->addBoxWhiskerLayer(DoubleArray(), DoubleArray(), ArrayMath(
                                                          DoubleArray(data, (int)(sizeof(data) / sizeof(data[0])))).add(DoubleArray(errData, (int)(
                                                                                                                                        sizeof(errData) / sizeof(errData[0])))), ArrayMath(DoubleArray(data, (int)(sizeof(data) /
                                                                                                                                                                                                                   sizeof(data[0])))).sub(DoubleArray(errData, (int)(sizeof(errData) / sizeof(errData[0])))),
            DoubleArray(data, (int)(sizeof(data) / sizeof(data[0]))), Chart::Transparent, 0xbb6633);

    // Set the line width to 2 pixels
    errLayer->setLineWidth(2);

    // Set the error zone to occupy half the space between the symbols
    errLayer->setDataGap(0.5);

    // Add a custom CDML text at the bottom right of the plot area as the logo
    c->addText(575, 247,
               "<*block,valign=absmiddle*><*img=small_molecule.png*> <*block*>"
               "<*font=timesbi.ttf,size=10,color=804040*>Molecular\nEngineering<*/*>")->setAlignment(
                Chart::BottomRight);

    // Output the chart
    c->makeChart("errline.png");


    QWidget * _w= new QWidget();
    QChartViewer * _v = new QChartViewer(_w);
    _v->setChart(c);

    //free up resources
    //delete c;
    return _w;

}


QWidget* Widget::addSurface()
{
    // The x and y coordinates of the grid
    double dataX[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double dataY[] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // The values at the grid points. In this example, we will compute the values using the formula
    // z = x * sin(y) + y * sin(x).
    double dataZ[(int)(sizeof(dataX) / sizeof(dataX[0])) * (int)(sizeof(dataY) / sizeof(dataY[0]))];
    for(int yIndex = 0; yIndex < (int)(sizeof(dataY) / sizeof(dataY[0])); ++yIndex) {
        double y = dataY[yIndex];
        for(int xIndex = 0; xIndex < (int)(sizeof(dataX) / sizeof(dataX[0])); ++xIndex) {
            double x = dataX[xIndex];
            dataZ[yIndex * (int)(sizeof(dataX) / sizeof(dataX[0])) + xIndex] = x * sin(y) + y * sin(
                        x);
        }
    }

    // Create a SurfaceChart object of size 720 x 600 pixels
    SurfaceChart *c = new SurfaceChart(720, 600);

    // Add a title to the chart using 20 points Times New Roman Italic font
    c->addTitle("Surface Energy Density   ", "timesi.ttf", 20);

    // Set the center of the plot region at (350, 280), and set width x depth x height to 360 x 360
    // x 270 pixels
    c->setPlotRegion(350, 280, 360, 360, 270);

    // Set the data to use to plot the chart
    c->setData(DoubleArray(dataX, (int)(sizeof(dataX) / sizeof(dataX[0]))), DoubleArray(dataY,
                                                                                        (int)(sizeof(dataY) / sizeof(dataY[0]))), DoubleArray(dataZ, (int)(sizeof(dataZ) / sizeof(
                                                                                                                                                               dataZ[0]))));

    // Spline interpolate data to a 80 x 80 grid for a smooth surface
    c->setInterpolation(80, 80);

    // Add a color axis (the legend) in which the left center is anchored at (645, 270). Set the
    // length to 200 pixels and the labels on the right side.
    c->setColorAxis(645, 270, Chart::Left, 200, Chart::Right);

    // Set the x, y and z axis titles using 10 points Arial Bold font
    c->xAxis()->setTitle("X (nm)", "arialbd.ttf", 10);
    c->yAxis()->setTitle("Y (nm)", "arialbd.ttf", 10);
    c->zAxis()->setTitle("Energy Density (J/m<*font,super*>2<*/font*>)", "arialbd.ttf", 10);

    // Output the chart
    c->makeChart("surface.jpg");

    //free up resources
    // delete c;

    QWidget *_widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);

    _v->setChart(c);
    return _widget;

}



//角表
QWidget*  Widget::addAngularMeter()
{

    // Create an AngularMeter object of size 300 x 300 pixels with transparent background
    AngularMeter *m = new AngularMeter(300, 300, Chart::Transparent);

    // Set the default text and line colors to white (0xffffff)
    m->setColor(Chart::TextColor, 0xffffff);
    m->setColor(Chart::LineColor, 0xffffff);

    // Center at (150, 150), scale radius = 128 pixels, scale angle 0 to 360 degrees
    m->setMeter(150, 150, 128, 0, 360);

    // Add a black (0x000000) circle with radius 148 pixels as background
    m->addRing(0, 148, 0x000000);

    // Add a ring between radii 139 and 147 pixels using the silver color with a light grey
    // (0xcccccc) edge as border
    m->addRing(139, 147, Chart::silverColor(), 0xcccccc);

    // Meter scale is 0 - 100, with major/minor/micro ticks every 10/5/1 units
    m->setScale(0, 100, 10, 5, 1);

    // Set the scale label style to 16pt Arial Italic. Set the major/minor/micro tick lengths to
    // 13/10/7 pixels pointing inwards, and their widths to 2/1/1 pixels.
    m->setLabelStyle("ariali.ttf", 16);
    m->setTickLength(-13, -10, -7);
    m->setLineWidth(0, 2, 1, 1);

    // Add a semi-transparent blue (0x7f6666ff) pointer using the default shape
    m->addPointer(25, 0x7f6666ff, 0x6666ff);

    // Add a semi-transparent red (0x7fff6666) pointer using the arrow shape
    m->addPointer(9, 0x7fff6666, 0xff6666)->setShape(Chart::ArrowPointer2);

    // Add a semi-transparent yellow (0x7fffff66) pointer using another arrow shape
    m->addPointer(51, 0x7fffff66, 0xffff66)->setShape(Chart::ArrowPointer);

    // Add a semi-transparent green (0x7f66ff66) pointer using the line shape
    m->addPointer(72, 0x7f66ff66, 0x66ff66)->setShape(Chart::LinePointer);

    // Add a semi-transparent grey (0x7fcccccc) pointer using the pencil shape
    m->addPointer(85, 0x7fcccccc, 0xcccccc)->setShape(Chart::PencilPointer);



    // Output the chart
    m->makeChart("angularpointer.png");

    //free up resources
    //delete m;

    QWidget *_widget= new QWidget();
    QChartViewer * _v= new QChartViewer(_widget);

    _v->setChart(m);
    return _widget;
}



void Widget::setSavePath()
{
    m_piechart->setImagePath(ui->ldtdir->text());
    m_histogram->setImagePath(ui->ldtdir->text());
    m_linechart->setImagePath(ui->ldtdir->text());
}

Widget::~Widget()
{
    delete ui;

    delete m_piechart;
    m_piechart=NULL;

    delete m_histogram;
    m_histogram=NULL;

    delete m_linechart;
    m_linechart=NULL;
}

void Widget::on_ptnsavedir_clicked()
{
    QFileDialog* openFilePath = new QFileDialog( this, " 请选择保存目录", "file");     //打开一个目录选择对话框
    openFilePath->setFileMode( QFileDialog::DirectoryOnly );
    if ( openFilePath->exec() == QDialog::Accepted )
    {

        //qDebug()<<openFilePath->directory().absolutePath();
        QString m_savePath=openFilePath->directory().absolutePath();


        //QString path=QDir::currentPath();//获取程序当前目录
        m_savePath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
        //QProcess::startDetached("explorer "+path);//打开上面获取的目录

        /*
        bool flag=false;
        QString temp2;
        for(int i=0;i!=m_savePath.size();++i)
        {
            if(m_savePath.at(i)==QChar('/'))
            {
                if(!flag)
                {
                    temp2.append('\\');
                }
                flag=true;
            }
            else
            {
                temp2.append(m_savePath.at(i));
                flag=false;
            }
        }
        */
        ui->ldtdir->setText(m_savePath);
    }

    setSavePath();
    delete openFilePath;
}

void Widget::on_ptnshowimg_clicked()
{
    QProcess::startDetached("explorer "+ui->ldtdir->text());//打开截图的目录
}
