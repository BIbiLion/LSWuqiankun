#include "toolboxwindow.h"
#include "mainwindow.h"
#include "diagramscene.h"
#include <QtGui>


ToolboxWindow::ToolboxWindow(QWidget *parent)
	: QWidget(parent)
{
 
	createWidget();
}

ToolboxWindow::ToolboxWindow ( QWidget *parent, Qt::WindowFlags f)
	: QWidget(parent,f)
{
	createWidget();
}

ToolboxWindow::~ToolboxWindow()
{

}

void ToolboxWindow::createWidget()
{
	gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
	toolBox = new QToolBox(this);
    toolBox->setObjectName(QString::fromUtf8("toolBox"));

	//基本图元--包含 直线，椭圆，矩形，文本
	basePage = new QWidget();
    basePage->setObjectName(QString::fromUtf8("basePage"));
    basePage->setGeometry(QRect(0, 0, 127, 228));
	toolBox->addItem(basePage,tr("基本图元"));
	QButtonGroup * baseButtonGroup = new QButtonGroup (basePage);
    baseButtonGroup->setExclusive(false);
    connect(baseButtonGroup, SIGNAL(buttonClicked(int )),
            this, SLOT(baseButtonGroupClicked(int)));
	
	//创建基本图元按钮
	createBasePageBox (basePage, baseButtonGroup);	

	//静态图元
	staticPage = new QWidget();
    staticPage->setObjectName(QString::fromUtf8("staticPage"));
    staticPage->setGeometry(QRect(0, 0, 127, 228));
	toolBox->addItem(staticPage,tr("静态图元"));
	QButtonGroup * staticButtonGroup = new QButtonGroup (staticPage);
    staticButtonGroup->setExclusive(false);
    connect(staticButtonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(staticButtonGroupClicked(int)));

	//创建静态图元按钮
	createStaticPageBox (staticPage, staticButtonGroup);

	dynPage = new QWidget();
    dynPage->setObjectName(QString::fromUtf8("staticPage"));
    dynPage->setGeometry(QRect(0, 0, 127, 228));
	toolBox->addItem(dynPage,tr("动态图元"));
	QButtonGroup * dynButtonGroup = new QButtonGroup (dynPage);
    dynButtonGroup->setExclusive(false);
    connect(dynButtonGroup, SIGNAL(buttonClicked(int)),
            this, SLOT(dynButtonGroupClicked(int)));

	//创建动态图元按钮
	createDynPageBox (dynPage, dynButtonGroup);

	funSetPage = new QWidget();
    funSetPage->setObjectName(QString::fromUtf8("funSetPage"));
    funSetPage->setGeometry(QRect(0, 0, 127, 228));
	toolBox->addItem(funSetPage,tr("功能设置"));
	//funSetGroup = new QGroupBox (funSetPage);

	//创建功能设置
	createFunSetPageBox (funSetPage);


	gridLayout->addWidget(toolBox, 0, 0, 1, 1);

	toolButton_select = NULL;

}

void ToolboxWindow::createBasePageBox(QWidget * parent, QButtonGroup * baseButtonGroup)
{
	toolButton_line_Hor = new QToolButton(parent);
	toolButton_line_Hor->setIcon(QIcon("images/graphicsitem/horizonalbeeline.png"));
	toolButton_line_Hor->setToolTip("直线");
    toolButton_line_Hor->setObjectName(QString::fromUtf8("toolButton_line_Hor"));
    toolButton_line_Hor->setGeometry(QRect(22, 2, 82, 21));
	baseButtonGroup->addButton(toolButton_line_Hor, 1);

	toolButton_line_Ver = new QToolButton(parent);
	toolButton_line_Ver->setIcon(QIcon("images/graphicsitem/verticalBeeline.png"));
	toolButton_line_Ver->setToolTip("直线");
    toolButton_line_Ver->setObjectName(QString::fromUtf8("toolButton_line_Ver"));
    toolButton_line_Ver->setGeometry(QRect(22, 26, 82, 21));
	baseButtonGroup->addButton(toolButton_line_Ver, 2);

	toolButton_ellipse = new QToolButton(parent);
	toolButton_ellipse->setIcon(QIcon("images/graphicsitem/ellipse.png"));
	toolButton_ellipse->setToolTip("椭圆");
    toolButton_ellipse->setObjectName(QString::fromUtf8("toolButton_ellipse"));
    toolButton_ellipse->setGeometry(QRect(22, 50, 82, 21));
	baseButtonGroup->addButton(toolButton_ellipse, 3);

	toolButton_rect = new QToolButton(parent);
	toolButton_rect->setIcon(QIcon("images/graphicsitem/rect.png"));
	toolButton_rect->setToolTip("矩形");
    toolButton_rect->setObjectName(QString::fromUtf8("toolButton_rect"));
    toolButton_rect->setGeometry(QRect(22,74, 82, 21));
	baseButtonGroup->addButton(toolButton_rect, 4);

	toolButton_text = new QToolButton(parent);
	toolButton_text->setIcon(QIcon("images/graphicsitem/text.png"));
	toolButton_text->setToolTip("文本");
    toolButton_text->setObjectName(QString::fromUtf8("toolButton_text"));
    toolButton_text->setGeometry(QRect(22, 98, 82, 21));
	baseButtonGroup->addButton(toolButton_text, 5);

	toolButton_LineArrow_Top = new QToolButton(parent);
	toolButton_LineArrow_Top->setIcon(QIcon("images/graphicsitem/topline.png"));
	toolButton_LineArrow_Top->setToolTip("线路");
    toolButton_LineArrow_Top->setObjectName(QString::fromUtf8("toolButton_LineArrow_Top"));
    toolButton_LineArrow_Top->setGeometry(QRect(22, 122, 82, 21));
	baseButtonGroup->addButton(toolButton_LineArrow_Top, 6);

	toolButton_LineArrow_Bom = new QToolButton(parent);
	toolButton_LineArrow_Bom->setIcon(QIcon("images/graphicsitem/bottomline.png"));
	toolButton_LineArrow_Bom->setToolTip("线路");
    toolButton_LineArrow_Bom->setObjectName(QString::fromUtf8("toolButton_LineArrow_Bom"));
    toolButton_LineArrow_Bom->setGeometry(QRect(22, 146, 82, 21));
	baseButtonGroup->addButton(toolButton_LineArrow_Bom, 7);

	toolButton_LineArrow_Lef = new QToolButton(parent);
	toolButton_LineArrow_Lef->setIcon(QIcon("images/graphicsitem/leftline.png"));
	toolButton_LineArrow_Lef->setToolTip("线路");
    toolButton_LineArrow_Lef->setObjectName(QString::fromUtf8("toolButton_LineArrow_Lef"));
    toolButton_LineArrow_Lef->setGeometry(QRect(22, 170, 82, 21));
	baseButtonGroup->addButton(toolButton_LineArrow_Lef,8);



	toolButton_LineArrow_Rig = new QToolButton(parent);
	toolButton_LineArrow_Rig->setIcon(QIcon("images/graphicsitem/rightline.png"));
	toolButton_LineArrow_Rig->setToolTip("线路");
    toolButton_LineArrow_Rig->setObjectName(QString::fromUtf8("toolButton_LineArrow_Rig"));
    toolButton_LineArrow_Rig->setGeometry(QRect(22, 194, 82, 21));
	baseButtonGroup->addButton(toolButton_LineArrow_Rig,9);

	toolButton_thirdangle = new QToolButton(parent);
	toolButton_thirdangle->setIcon(QIcon("images/graphicsitem/triangle.png"));
	toolButton_thirdangle->setToolTip("三角形");
    toolButton_thirdangle->setObjectName(QString::fromUtf8("toolButton_thirdangle"));
    toolButton_thirdangle->setGeometry(QRect(22, 218, 82, 21));
	baseButtonGroup->addButton(toolButton_thirdangle, 10);



}

void ToolboxWindow::createStaticPageBox(QWidget * parent, QButtonGroup * baseButtonGroup)
{

	toolButton_jtcompensator_Split = new QToolButton(parent);
	toolButton_jtcompensator_Split->setIcon(QIcon("images/graphicsitem/splitReactor.png"));
	toolButton_jtcompensator_Split->setToolTip("分裂电抗器");
    toolButton_jtcompensator_Split->setObjectName(QString::fromUtf8("toolButton_jtcompensator_Split"));
    toolButton_jtcompensator_Split->setGeometry(QRect(22, 2, 82, 21));
	baseButtonGroup->addButton(toolButton_jtcompensator_Split, 1);

	toolButton_jtbreakcompensator = new QToolButton(parent);
	toolButton_jtbreakcompensator->setIcon(QIcon("images/graphicsitem/reactor.png"));
	toolButton_jtbreakcompensator->setToolTip("电抗器");
    toolButton_jtbreakcompensator->setObjectName(QString::fromUtf8("toolButton_jtbreakcompensator"));
    toolButton_jtbreakcompensator->setGeometry(QRect(22, 26, 82, 21));
	baseButtonGroup->addButton(toolButton_jtbreakcompensator, 2);

	toolButton_jtct_Hor = new QToolButton(parent);
	toolButton_jtct_Hor->setIcon(QIcon("images/graphicsitem/capacitor.png"));
	toolButton_jtct_Hor->setToolTip("电容器");
    toolButton_jtct_Hor->setObjectName(QString::fromUtf8("toolButton_jtct_Hor"));
    toolButton_jtct_Hor->setGeometry(QRect(22, 50, 82, 21));
	baseButtonGroup->addButton(toolButton_jtct_Hor, 3);

	toolButton_jtct_Ver = new QToolButton(parent);
	toolButton_jtct_Ver->setIcon(QIcon("images/graphicsitem/capacitor.png"));
	toolButton_jtct_Ver->setToolTip("电容器");
    toolButton_jtct_Ver->setObjectName(QString::fromUtf8("toolButton_jtct_Ver"));
    toolButton_jtct_Ver->setGeometry(QRect(22, 74, 82, 21));
	baseButtonGroup->addButton(toolButton_jtct_Ver, 4);

	toolButton_jteachfelli_Lef = new QToolButton(parent);
	toolButton_jteachfelli_Lef->setIcon(QIcon("images/graphicsitem/leftcurrentInductance.png"));
	toolButton_jteachfelli_Lef->setToolTip("电流互感器");
    toolButton_jteachfelli_Lef->setObjectName(QString::fromUtf8("toolButton_jteachfelli_Lef"));
    toolButton_jteachfelli_Lef->setGeometry(QRect(22, 98, 82, 21));
	baseButtonGroup->addButton(toolButton_jteachfelli_Lef, 5);

	toolButton_jteachfelli_Rig = new QToolButton(parent);
	toolButton_jteachfelli_Rig->setIcon(QIcon("images/graphicsitem/rightcurrentInductance.png"));
	toolButton_jteachfelli_Rig->setToolTip("电流互感器");
    toolButton_jteachfelli_Rig->setObjectName(QString::fromUtf8("toolButton_jteachfelli_Rig"));
    toolButton_jteachfelli_Rig->setGeometry(QRect(22, 122, 82, 21));
	baseButtonGroup->addButton(toolButton_jteachfelli_Rig, 6);

	toolButton_jteachfellv = new QToolButton(parent);
	toolButton_jteachfellv->setIcon(QIcon("images/graphicsitem/voltageInductance.png"));
	toolButton_jteachfellv->setToolTip("电压互感器");
    toolButton_jteachfellv->setObjectName(QString::fromUtf8("toolButton_jteachfellv"));
    toolButton_jteachfellv->setGeometry(QRect(22, 146, 82, 21));
	baseButtonGroup->addButton(toolButton_jteachfellv, 7);

	toolButton_jtground_Hor = new QToolButton(parent);
	toolButton_jtground_Hor->setIcon(QIcon("images/graphicsitem/horizonalbottomLine.png"));
	toolButton_jtground_Hor->setToolTip("接地");
    toolButton_jtground_Hor->setObjectName(QString::fromUtf8("toolButton_jtground_Hor"));
    toolButton_jtground_Hor->setGeometry(QRect(22, 170, 82, 21));
	baseButtonGroup->addButton(toolButton_jtground_Hor, 8);

	toolButton_jtground_Ver = new QToolButton(parent);
	toolButton_jtground_Ver->setIcon(QIcon("images/graphicsitem/verticalbottomLine.png"));
	toolButton_jtground_Ver->setToolTip("接地");
    toolButton_jtground_Ver->setObjectName(QString::fromUtf8("toolButton_jtground_Ver"));
    toolButton_jtground_Ver->setGeometry(QRect(22, 194, 82, 21));
	baseButtonGroup->addButton(toolButton_jtground_Ver, 9);

	toolButton_jtinsure_Hor = new QToolButton(parent);
	toolButton_jtinsure_Hor->setIcon(QIcon("images/graphicsitem/horizonalcontainer.png"));
	toolButton_jtinsure_Hor->setToolTip("容断器");
    toolButton_jtinsure_Hor->setObjectName(QString::fromUtf8("toolButton_jtinsure_Hor"));
    toolButton_jtinsure_Hor->setGeometry(QRect(22, 218, 82, 21));
	baseButtonGroup->addButton(toolButton_jtinsure_Hor, 10);

	toolButton_jtinsure_Ver = new QToolButton(parent);
	toolButton_jtinsure_Ver->setIcon(QIcon("images/graphicsitem/verticalcontainer.png"));
	toolButton_jtinsure_Ver->setToolTip("容断器");
    toolButton_jtinsure_Ver->setObjectName(QString::fromUtf8("toolButton_jtinsure_Ver"));
    toolButton_jtinsure_Ver->setGeometry(QRect(22, 242, 82, 21));
	baseButtonGroup->addButton(toolButton_jtinsure_Ver, 11);

	toolButton_jtstar = new QToolButton(parent);
	toolButton_jtstar->setIcon(QIcon("images/graphicsitem/start.png"));
	toolButton_jtstar->setToolTip("星形");
    toolButton_jtstar->setObjectName(QString::fromUtf8("toolButton_jtstar"));
    toolButton_jtstar->setGeometry(QRect(22, 266, 82, 21));
	baseButtonGroup->addButton(toolButton_jtstar, 12);

	toolButton_jtterminal = new QToolButton(parent);
	toolButton_jtterminal->setIcon(QIcon("images/graphicsitem/terminal.png"));
	toolButton_jtterminal->setToolTip("终端器");
    toolButton_jtterminal->setObjectName(QString::fromUtf8("toolButton_jtterminal"));
    toolButton_jtterminal->setGeometry(QRect(22,290, 82, 21));
	baseButtonGroup->addButton(toolButton_jtterminal, 13);

	toolButton_jtthunder = new QToolButton(parent);
	//toolButton_jtthunder->setIcon(QIcon("images/graphicsitem/start.png"));
	//toolButton_jtthunder->setToolTip("避雷器");
    toolButton_jtthunder->setObjectName(QString::fromUtf8("toolButton_jtthunder"));
    toolButton_jtthunder->setGeometry(QRect(22, 314, 82, 21));
	toolButton_jtthunder->setText("避雷器");
	baseButtonGroup->addButton(toolButton_jtthunder,14);


}

void ToolboxWindow::createDynPageBox(QWidget * parent, QButtonGroup * baseButtonGroup)
{

	toolButton_dtzyswitch_Hor = new QToolButton(parent);
	toolButton_dtzyswitch_Hor->setIcon(QIcon("images/graphicsitem/horizonalkniveSwitch.png"));
	toolButton_dtzyswitch_Hor->setToolTip("刀闸开关");
    toolButton_dtzyswitch_Hor->setObjectName(QString::fromUtf8("toolButton_dtzyswitch_Hor"));
    toolButton_dtzyswitch_Hor->setGeometry(QRect(22, 2, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzyswitch_Hor, 1);

	toolButton_dtzyswitch_Ver = new QToolButton(parent);
	toolButton_dtzyswitch_Ver->setIcon(QIcon("images/graphicsitem/verticalkniveSwitch.png"));
	toolButton_dtzyswitch_Ver->setToolTip("刀闸开关");
    toolButton_dtzyswitch_Ver->setObjectName(QString::fromUtf8("toolButton_dtzyswitch_Ver"));
    toolButton_dtzyswitch_Ver->setGeometry(QRect(22, 26, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzyswitch_Ver, 2);

	toolButton_dtzybreaker_Hor = new QToolButton(parent);
	toolButton_dtzybreaker_Hor->setIcon(QIcon("images/graphicsitem/horizonalbreaker.png"));
	toolButton_dtzybreaker_Hor->setToolTip("断路器");
    toolButton_dtzybreaker_Hor->setObjectName(QString::fromUtf8("toolButton_dtzybreaker_Hor"));
    toolButton_dtzybreaker_Hor->setGeometry(QRect(22, 50, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzybreaker_Hor,3);

	toolButton_dtzybreaker_Ver = new QToolButton(parent);
	toolButton_dtzybreaker_Ver->setIcon(QIcon("images/graphicsitem/verticalbreaker.png"));
	toolButton_dtzybreaker_Ver->setToolTip("断路器");
    toolButton_dtzybreaker_Ver->setObjectName(QString::fromUtf8("toolButton_dtzybreaker_Ver"));
    toolButton_dtzybreaker_Ver->setGeometry(QRect(22, 74, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzybreaker_Ver, 4);

	toolButton_dtzyengine = new QToolButton(parent);
	toolButton_dtzyengine->setIcon(QIcon("images/graphicsitem/powerHouse.png"));
	toolButton_dtzyengine->setToolTip("发电机");
    toolButton_dtzyengine->setObjectName(QString::fromUtf8("toolButton_dtzyengine"));
    toolButton_dtzyengine->setGeometry(QRect(22, 98, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzyengine, 5);

	toolButton_dtzy2trans = new QToolButton(parent);
	toolButton_dtzy2trans->setIcon(QIcon("images/graphicsitem/transformer1.png"));
	toolButton_dtzy2trans->setToolTip("变压器");
    toolButton_dtzy2trans->setObjectName(QString::fromUtf8("toolButton_dtzy2trans"));
    toolButton_dtzy2trans->setGeometry(QRect(22, 122, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzy2trans, 6);

	toolButton_dtzy3trans = new QToolButton(parent);
	toolButton_dtzy3trans->setIcon(QIcon("images/graphicsitem/transformer.png"));
	toolButton_dtzy3trans->setToolTip("变压器");
    toolButton_dtzy3trans->setObjectName(QString::fromUtf8("toolButton_dtzyswitch_Hor"));
    toolButton_dtzy3trans->setGeometry(QRect(22, 146, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzy3trans,7);

	toolButton_dtzygeneratrix = new QToolButton(parent);
	toolButton_dtzygeneratrix->setIcon(QIcon("images/graphicsitem/generatrix.png"));
	toolButton_dtzygeneratrix->setToolTip("母线");
    toolButton_dtzygeneratrix->setObjectName(QString::fromUtf8("toolButton_dtzygeneratrix"));
    toolButton_dtzygeneratrix->setGeometry(QRect(22, 170, 82, 21));
	baseButtonGroup->addButton(toolButton_dtzygeneratrix, 8);

}

void ToolboxWindow::createFunSetPageBox(QWidget * parent)
{

	toolButton_penColor = new QToolButton(parent);
	toolButton_penColor->setIcon(QIcon("images/pen.png"));
	toolButton_penColor->setToolTip("画笔颜色");
    toolButton_penColor->setObjectName(QString::fromUtf8("toolButton_penColor"));
    toolButton_penColor->setGeometry(QRect(22, 2, 82, 21));
	connect(toolButton_penColor,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	
	combox_penWidth = new QComboBox(parent);
	combox_penWidth->setGeometry(QRect(22, 26, 82, 21));
	for (int i = 1; i < 21; i++)
        combox_penWidth->addItem(QString().setNum(i));

	connect(combox_penWidth, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(penWidthComBoxChanged(const QString &)));

	toolButton_fillColor = new QToolButton(parent);
	toolButton_fillColor->setIcon(QIcon("images/fill.png"));
	toolButton_fillColor->setToolTip("填充颜色");
    toolButton_fillColor->setObjectName(QString::fromUtf8("toolButton_penColor"));
    toolButton_fillColor->setGeometry(QRect(22, 50, 82, 21));
	connect(toolButton_fillColor,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_backgroundColor = new QToolButton(parent);
	boolButton_backgroundColor->setIcon(QIcon("images/fill.png"));
	boolButton_backgroundColor->setToolTip("背景颜色");
    boolButton_backgroundColor->setObjectName(QString::fromUtf8("boolButton_backgroundColor"));
    boolButton_backgroundColor->setGeometry(QRect(22, 74, 82, 21));
	connect(boolButton_backgroundColor,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_font = new QToolButton(parent);
	boolButton_font->setIcon(QIcon("images/font.png"));
	boolButton_font->setToolTip("字体");
    boolButton_font->setObjectName(QString::fromUtf8("boolButton_font"));
    boolButton_font->setGeometry(QRect(22, 98, 82, 21));
	connect(boolButton_font,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_sceneSize = new QToolButton(parent);
	boolButton_sceneSize->setIcon(QIcon("images/font.png"));
	boolButton_sceneSize->setToolTip("场景大小");
    boolButton_sceneSize->setObjectName(QString::fromUtf8("boolButton_sceneSize"));
    boolButton_sceneSize->setGeometry(QRect(22, 122, 82, 21));
	connect(boolButton_sceneSize,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_topArrange = new QToolButton(parent);
	boolButton_topArrange->setIcon(QIcon("images/top.png"));
	boolButton_topArrange->setToolTip("上对齐");
    boolButton_topArrange->setObjectName(QString::fromUtf8("boolButton_topArrange"));
    boolButton_topArrange->setGeometry(QRect(22, 146, 82, 21));
	connect(boolButton_topArrange,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_bottomArrange = new QToolButton(parent);
	boolButton_bottomArrange->setIcon(QIcon("images/bottom.png"));
	boolButton_bottomArrange->setToolTip("下对齐");
    boolButton_bottomArrange->setObjectName(QString::fromUtf8("boolButton_bottomArrange"));
    boolButton_bottomArrange->setGeometry(QRect(22, 170, 82, 21));
	connect(boolButton_bottomArrange,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_leftArrange = new QToolButton(parent);
	boolButton_leftArrange->setIcon(QIcon("images/left.png"));
	boolButton_leftArrange->setToolTip("左对齐");
    boolButton_leftArrange->setObjectName(QString::fromUtf8("boolButton_leftArrange"));
    boolButton_leftArrange->setGeometry(QRect(22, 194, 82, 21));
	connect(boolButton_leftArrange,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));

	boolButton_rightArrange = new QToolButton(parent);
	boolButton_rightArrange->setIcon(QIcon("images/right.png"));
	boolButton_rightArrange->setToolTip("右对齐");
    boolButton_rightArrange->setObjectName(QString::fromUtf8("boolButton_rightArrange"));
    boolButton_rightArrange->setGeometry(QRect(22, 218, 82, 21));
	connect(boolButton_rightArrange,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));


    boolButton_editMode = new QToolButton(parent);
    boolButton_editMode->setObjectName(QString::fromUtf8("boolButton_editMode"));
    boolButton_editMode->setGeometry(QRect(22, 242, 82, 21));
	if (MainWindow::m_self->editShowModel())
	    boolButton_editMode->setText("显示模式");
	else
		boolButton_editMode->setText("编辑模式");
	connect(boolButton_editMode,  SIGNAL(clicked ( bool )), this, SLOT(toolButtonClicked(bool )));
	
}

void ToolboxWindow::baseButtonGroupClicked(int id)
{

	  switch(id)
	  {
	  case 1:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalBeeline);
		  break;
	  case 2:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalBeeline);
		  break;
	  case 3:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertElipase);
		  break;
	  case 4:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertRectangle);
		  break;
	  case 5:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertText);
		  break;
	  case 6:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Top_Line);
		  break;
	  case 7:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Bottom_Line);
		  break;
	  case 8:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Left_Line);
		  break;
	  case 9:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Right_Line);
		  break;
	  case 10:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertTriangle);
		  break;
	  default:
		  break;
	  }


}

void ToolboxWindow::staticButtonGroupClicked(int id)
{

     switch(id)
	  {
	  case 1:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertSplitReactor);
		  break;
	  case 2:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertReactor);
		  break;
	  case 3:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalCapacitor);
		  break;
	  case 4:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalCapacitor);
		  break;
	  case 5:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Left_CurrentInductance);
		  break;
	  case 6:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_Right_CurrentInductance);
		  break;
	  case 7:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalVoltageInductance);
		  break;
	  case 8:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalBottomLine);
		  break;
	  case 9:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalBottomLine);
		  break;
	  case 10:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalContainer);
		  break;
	  case 11:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalContainer);
		  break;
	  case 12:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertStarry);
		  break;
  	  case 13:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalTerminal);
		  break;
  	  case 14:
		   //MainWindow::m_self->scene->setMode(DiagramScene::InsertTriangle);
		  break;
	  default:
		  break;
	  }
}

void ToolboxWindow::dynButtonGroupClicked(int id)
{

	switch(id)
	  {
	  case 1:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalKnivesSwitch);
		  break;
	  case 2:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalKnivesSwitch);
		  break;
	  case 3:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_HorizonalBreaker);
		  break;
	  case 4:
		   MainWindow::m_self->scene->setMode(DiagramScene::Insert_VerticalBreaker);
		  break;
	  case 5:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertPowerHouse);
		  break;
	  case 6:
		   MainWindow::m_self->scene->setMode(DiagramScene::Inserttransformer1);
		  break;
	  case 7:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertTransformer);
		  break;
	  case 8:
		   MainWindow::m_self->scene->setMode(DiagramScene::InsertGeneratrix);
		  break;

	 default:
		  break;
	  }
}


void ToolboxWindow::penWidthComBoxChanged(const QString &strPenWidth)
{
	MainWindow::m_self->scene->setPenWidth(strPenWidth.toInt());
}

void ToolboxWindow::toolButtonClicked( bool checked  )
{
	QToolButton *toolBtn = qobject_cast<QToolButton *>(sender());
    
	if (toolBtn == toolButton_penColor)
		MainWindow::m_self->setPenColor();
	else if (toolBtn == toolButton_fillColor)
		MainWindow::m_self->setFillColor();
	else if (toolBtn == boolButton_backgroundColor)
		MainWindow::m_self->setBackgroundColor();
	else if (toolBtn == boolButton_font)
		MainWindow::m_self->setFont();
	else if (toolBtn == boolButton_sceneSize)
		MainWindow::m_self->setSceneSize();
   else if (toolBtn == boolButton_topArrange)
		MainWindow::m_self->scene->setTopArrange();
	else if (toolBtn == boolButton_bottomArrange)
		MainWindow::m_self->scene->setbottom();
	else if (toolBtn == boolButton_leftArrange)
		MainWindow::m_self->scene->setLeftArrange();
	else if (toolBtn == boolButton_rightArrange)
		MainWindow::m_self->scene->setRightArrange();
    else if (toolBtn == boolButton_editMode)
	{
		if (MainWindow::m_self->editShowModel())
		{  
		    boolButton_editMode->setText("编辑模式");
			MainWindow::m_self->setEditShowModel(false);
		}
		else
		{
			boolButton_editMode->setText("显示模式");
			MainWindow::m_self->setEditShowModel(true);
		}
	}
	
		
	

}

