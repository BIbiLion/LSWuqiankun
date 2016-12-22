#include "mainwindow.h"
#include "dirtreewidget.h"
#include "diagramscene.h"
#include "inputscenesizedialog.h"
#include "itemgraphicsview.h"
#include "toolboxwindow.h"
#include <QtGui>

MainWindow * MainWindow::m_self = 0;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
    initVar();
	createAction();
	createMenus();
	createToolBar();
	createDock();	
	initWidget();
	
}

MainWindow::~MainWindow()
{

}

void MainWindow::initVar()
{
	
	m_self = this;
	angle = 0.0;
	m_Flag = true;
	m_fullScreenFlag = false;

	m_fileName = "";
	m_progName = "SVG/SCD电力图形编辑系统";

	setWindowTitle(m_progName);

}

void MainWindow::initWidget()
{
	scene = new DiagramScene(contextMenu,this);
	view = new ItemGraphicsView(scene);
	scene->setEditShowModel(editShowModel());

	m_textEdit = new QLineEdit (view);
	m_textEdit->move (100,100);
	m_textEdit->setText ("");
	m_textEdit->hide();

    this->setCentralWidget(view);

}

void MainWindow::showTextEdit (QPointF & pos,bool flag)
{
	if (flag)
	{
		m_textEdit->move(pos.x(),pos.y());
		m_textEdit->show ();	
	}else
	{
		m_textEdit->hide();
	}
}

void MainWindow::setTextEdit(QString str)
{

	m_textEdit->setText(str);
}

void MainWindow::createAction()
{
	newAction	    = new QAction(QIcon("images/new.png"),tr("新建(&N)"), this); 
	importAction    = new QAction(QIcon("images/open.png"),tr("打开(&O)"), this);  
	importAction    = new QAction(tr("打开(&O)"), this);  
    saveAction	    = new QAction(QIcon("images/save.png"),tr("保存(&S)"), this);  
	otherSaveAction = new QAction(QIcon("images/save.png"),tr("另存为"), this);
	saveScdAction   = new QAction(QIcon("images/save.png"),tr("保存SCD"), this);
	openScdAction   = new QAction(QIcon("images/open.png"),tr("打开SCD"), this);
	printAction     = new QAction(QIcon("images/print.png"),tr("打印(&P)"), this);
    
	printViewAction = new QAction(tr("打印预览(&V)"), this);
	printSetAction  = new QAction(tr("打印设置(&R)"), this);
	exitAction      = new QAction(tr("退出(&X)"), this);

	recallAction    = new QAction(QIcon("images/undo.png"),tr("撤消(&Z)"), this); 
	copyAction      = new QAction(QIcon("images/copy.png"),tr("复制(&C)"), this);  
	pasveAction     = new QAction(QIcon("images/paste.png"),tr("粘贴(&V)"), this); 
	cutAction       = new QAction(QIcon("images/cut.png"),tr("剪切(&X)"), this);
 
    arrangeAction      = new QAction(tr("排列"), this);
	circumgyrateAction = new QAction(tr("旋转"), this);
  
	selectAllItemAction  = new QAction(tr("选中所有图元"), this);
	selectAllEquipAction = new QAction(tr("选中所有装置"), this);
	
	leftArrangeAction    = new QAction(QIcon("images/left.png"),tr("左对齐"), this);
	rihgtArrangeAction   = new QAction(QIcon("images/right.png"),tr("右对齐"), this);
	topArrangeAction     = new QAction(QIcon("images/top.png"),tr("顶端对齐"), this);
	bottomArrangeAction  = new QAction(QIcon("images/bottom.png"),tr("底端对齐"), this);

	penColorAction       = new QAction(QIcon("images/pen.png"),tr("设置画笔颜色"), this);
	fillColorAction      = new QAction(QIcon("images/fill.png"),tr("设置填充颜色"), this);
	sceneSizeAction      = new QAction(tr("设置场景大小"), this);
	backGroundAction     = new QAction(tr("设置场景的背景色"), this);
	fontAction           = new QAction(QIcon("images/font.png"),tr("设置字体"), this);
	fullScreenAction     = new QAction(QIcon("images/actualsize.png"),tr("全屏"), this);
	updateImageAction    = new QAction(QIcon("images/actualsize.png"),tr("刷新图形"), this);
	

	beckonSettingAction  = new QAction(tr("召唤定值量"), this);
	beckonSwitchAction   = new QAction(tr("召唤开关量"), this);

	toolBarAction        = new QAction(tr("工具栏"), this);
	statusBarAction      = new QAction(tr("状态栏"), this);
	dirTreeAction        = new QAction(tr("目录树"), this);

	stationAction                    = new QAction(QIcon("images/graphicsitem/equip.png"),tr("站"), this);
    equipAction                      = new QAction(QIcon("images/graphicsitem/equip.png"),tr("装置"), this);

    selectAction					 = new QAction(QIcon("images/graphicsitem/select.png"),tr("选择"), this);
	horizonalBeelineAction           = new QAction(QIcon("images/graphicsitem/horizonalbeeline.png"),tr("直线"), this);
	verticalBeelineAction            = new QAction(QIcon("images/graphicsitem/verticalBeeline.png"),tr("直线"), this);
	rectAction                       = new QAction(QIcon("images/graphicsitem/rect.png"),tr("矩形"), this);
	startAction                      = new QAction(QIcon("images/graphicsitem/start.png"),tr("星型"), this);
	ellipseAction                    = new QAction(QIcon("images/graphicsitem/ellipse.png"),tr("椭圆"), this);
	triangleAction                   = new QAction(QIcon("images/graphicsitem/triangle.png"),tr("三角形"), this);
	horizonalCapacitorAction         = new QAction(QIcon("images/graphicsitem/capacitor.png"),tr("电容器"), this);
	verticalCapacitorAction          = new QAction(QIcon("images/graphicsitem/capacitor.png"),tr("电容器"), this);
	terminalAction                   = new QAction(QIcon("images/graphicsitem/terminal.png"),tr("终端"), this);
	horizonalContainerAction         = new QAction(QIcon("images/graphicsitem/horizonalcontainer.png"),tr("容断器"), this);
    verticalContainerAction          = new QAction(QIcon("images/graphicsitem/verticalcontainer.png"),tr("容断器"), this);
	verticalKnivesSwitchAction       = new QAction(QIcon("images/graphicsitem/verticalkniveSwitch.png"),tr("刀闸"), this);
	horizonalKnivesSwitchAction      = new QAction(QIcon("images/graphicsitem/horizonalkniveSwitch.png"),tr("刀闸"), this);
	horizonalBottomLineAction        = new QAction(QIcon("images/graphicsitem/horizonalbottomLine.png"),tr("接地线"), this);
	verticalBottomLineAction         = new QAction(QIcon("images/graphicsitem/verticalbottomLine.png"),tr("接地线"), this);
	generatrixAction				 = new QAction(QIcon("images/graphicsitem/generatrix.png"),tr("母线"), this);
	horizonalCurrentInductanceAction = new QAction(QIcon("images/graphicsitem/leftcurrentInductance.png"),tr("电流互感器"), this);
	verticalCurrentInductanceAction  = new QAction(QIcon("images/graphicsitem/rightcurrentInductance.png"),tr("电流互感器"), this);
	voltageInductanceAction          = new QAction(QIcon("images/graphicsitem/voltageInductance.png"),tr("电压互感器"), this);
	horizonalBreakerAction           = new QAction(QIcon("images/graphicsitem/horizonalbreaker.png"),tr("断路器"), this);
	verticalBreakerAction            = new QAction(QIcon("images/graphicsitem/verticalbreaker.png"),tr("断路器"), this);
	splitReactorAction               = new QAction(QIcon("images/graphicsitem/splitReactor.png"),tr("分裂电抗器"), this);
	reactorAction                    = new QAction(QIcon("images/graphicsitem/reactor.png"),tr("电抗器"), this);
	transformerAction                = new QAction(QIcon("images/graphicsitem/transformer.png"),tr("变压器"), this);
	transformer1Action               = new QAction(QIcon("images/graphicsitem/transformer1.png"),tr("变压器"), this);
	powerHouseAction                 = new QAction(QIcon("images/graphicsitem/powerHouse.png"),tr("发电厂"), this);
	topLineAction                    = new QAction(QIcon("images/graphicsitem/topline.png"),tr("线路"), this);
	bottomLineAction                 = new QAction(QIcon("images/graphicsitem/bottomline.png"),tr("线路"), this);
	leftLineAction                   = new QAction(QIcon("images/graphicsitem/leftline.png"),tr("线路"), this);
	rightLineAction                  = new QAction(QIcon("images/graphicsitem/rightline.png"),tr("线路"), this);
	textAction                       = new QAction(QIcon("images/graphicsitem/text.png"),tr("文本"), this);
	
	connect(newAction,		 SIGNAL(triggered()), this, SLOT(newEdit()));
	connect(importAction,    SIGNAL(triggered()), this, SLOT(open()));
	connect(saveAction,      SIGNAL(triggered()), this, SLOT(save()));
	connect(otherSaveAction, SIGNAL(triggered()), this, SLOT(otherSave()));
	connect(saveScdAction,   SIGNAL(triggered()), this, SLOT(saveSCD()));
	connect(openScdAction,   SIGNAL(triggered()), this, SLOT(openSCD()));
	connect(exitAction,      SIGNAL(triggered()), this, SLOT(close()));

    connect(stationAction ,      SIGNAL(triggered()), this, SLOT(subEdit()));
    connect(equipAction ,        SIGNAL(triggered()), this, SLOT(subEdit()));
	connect(circumgyrateAction,  SIGNAL(triggered()), this, SLOT(setAngle()));
	connect(cutAction,           SIGNAL(triggered()), this, SLOT(deleteItem()));
	connect(selectAllItemAction, SIGNAL(triggered()), this, SLOT(selectAllItem()));
	connect(backGroundAction,    SIGNAL(triggered()), this, SLOT(setBackgroundColor()));
	connect(sceneSizeAction,     SIGNAL(triggered()), this, SLOT(setSceneSize()));
	
	connect(selectAction,                     SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalBeelineAction,           SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalBeelineAction,            SIGNAL(triggered()), this, SLOT(setMode()));
	connect(rectAction,                       SIGNAL(triggered()), this, SLOT(setMode()));
	connect(startAction,                      SIGNAL(triggered()), this, SLOT(setMode()));
	connect(ellipseAction,                    SIGNAL(triggered()), this, SLOT(setMode()));
	connect(triangleAction,                   SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalCapacitorAction,         SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalCapacitorAction,          SIGNAL(triggered()), this, SLOT(setMode()));
	connect(terminalAction,                   SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalContainerAction,         SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalContainerAction,          SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalKnivesSwitchAction,       SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalKnivesSwitchAction,      SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalBottomLineAction,        SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalBottomLineAction,         SIGNAL(triggered()), this, SLOT(setMode()));
	connect(generatrixAction,                 SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalCurrentInductanceAction, SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalCurrentInductanceAction,  SIGNAL(triggered()), this, SLOT(setMode()));
	connect(voltageInductanceAction,		  SIGNAL(triggered()), this, SLOT(setMode()));
	connect(horizonalBreakerAction,           SIGNAL(triggered()), this, SLOT(setMode()));
	connect(verticalBreakerAction,            SIGNAL(triggered()), this, SLOT(setMode()));
	connect(generatrixAction,                 SIGNAL(triggered()), this, SLOT(setMode()));
	connect(splitReactorAction,               SIGNAL(triggered()), this, SLOT(setMode()));
	connect(reactorAction,                    SIGNAL(triggered()), this, SLOT(setMode()));
	connect(transformerAction,                SIGNAL(triggered()), this, SLOT(setMode()));
	connect(transformer1Action,               SIGNAL(triggered()), this, SLOT(setMode()));
	connect(powerHouseAction,                 SIGNAL(triggered()), this, SLOT(setMode()));
	connect(topLineAction,                    SIGNAL(triggered()), this, SLOT(setMode()));
	connect(bottomLineAction,                 SIGNAL(triggered()), this, SLOT(setMode()));
	connect(leftLineAction,                   SIGNAL(triggered()), this, SLOT(setMode()));
	connect(rightLineAction,                  SIGNAL(triggered()), this, SLOT(setMode()));
	connect(textAction,                       SIGNAL(triggered()), this, SLOT(setMode()));
 
    connect(penColorAction,   SIGNAL(triggered()), this, SLOT(setContextMenuSel()));
	connect(fillColorAction,  SIGNAL(triggered()), this, SLOT(setContextMenuSel()));
	connect(sceneSizeAction,  SIGNAL(triggered()), this, SLOT(setContextMenuSel()));
	connect(backGroundAction, SIGNAL(triggered()), this, SLOT(setContextMenuSel()));
	connect(fontAction,       SIGNAL(triggered()), this, SLOT(setContextMenuSel()));
    connect(leftArrangeAction,   SIGNAL(triggered()), this, SLOT(setArrange()));
	connect(rihgtArrangeAction,  SIGNAL(triggered()), this, SLOT(setArrange()));
	connect(topArrangeAction,    SIGNAL(triggered()), this, SLOT(setArrange()));
	connect(bottomArrangeAction, SIGNAL(triggered()), this, SLOT(setArrange()));
	connect(fullScreenAction, SIGNAL(triggered()),    this, SLOT(setWindowFullScreen()));

	connect(copyAction,  SIGNAL(triggered()), this, SLOT(itemCopy()));
	connect(pasveAction, SIGNAL(triggered()), this, SLOT(itemPasv()));
	connect(fontAction,  SIGNAL(triggered()), this, SLOT(setFont()));


	printAction->setShortcut(tr("Ctrl+P"));
    saveAction->setShortcut(tr("Ctrl+S"));
    importAction->setShortcut(tr("Ctrl+O"));
    exitAction->setShortcut(tr("Ctrl+X")); 
	newAction->setShortcut(tr("Ctrl+N"));

	recallAction->setShortcut(tr("Ctrl+Z"));
	copyAction->setShortcut(tr("Ctrl+C"));
	pasveAction->setShortcut(tr("Ctrl+V"));
	cutAction->setShortcut(QKeySequence::Delete);
	selectAllItemAction->setShortcut(tr("Ctrl+A"));

}


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("文件(&F)"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(importAction);
    fileMenu->addAction(saveAction);
	fileMenu->addAction(otherSaveAction);
	fileMenu->addAction(openScdAction);
	fileMenu->addAction(saveScdAction);
	fileMenu->addSeparator();
	fileMenu->addAction(printAction);
	fileMenu->addAction(printViewAction);
	fileMenu->addAction(printSetAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

    graphicsOperateMenu = menuBar()->addMenu(tr("画图操作(&D)"));
	graphicsOperateMenu->addAction(recallAction);
	graphicsOperateMenu->addSeparator();
	graphicsOperateMenu->addAction(copyAction);
	graphicsOperateMenu->addAction(pasveAction);
	graphicsOperateMenu->addAction(cutAction);
	graphicsOperateMenu->addSeparator();
	graphicsOperateMenu->addAction(arrangeAction);
	graphicsOperateMenu->addAction(circumgyrateAction);
	graphicsOperateMenu->addSeparator();
	graphicsOperateMenu->addAction(selectAllItemAction);
	graphicsOperateMenu->addAction(selectAllEquipAction);

    graphicsSetMenu = menuBar()->addMenu(tr("画图设置(&S)"));
	graphicsSetMenu->addAction(penColorAction);
	graphicsSetMenu->addAction(fillColorAction);
	graphicsSetMenu->addSeparator();
	graphicsSetMenu->addAction(sceneSizeAction);
	graphicsSetMenu->addAction(backGroundAction);
	graphicsSetMenu->addSeparator();
	graphicsSetMenu->addAction(fontAction);
 

	viewMneu = menuBar()->addMenu(tr("查看(&V)"));
    viewMneu->addAction(toolBarAction);
	viewMneu->addAction(statusBarAction);
	viewMneu->addSeparator();
	viewMneu->addAction(dirTreeAction);

	helpMenu = menuBar()->addMenu(tr("帮助(&H)"));


	//创建右健菜单
	contextMenu = new QMenu(this);
    addContextMenuAction(true,false);
	
}

void MainWindow::addContextMenuAction(bool flag,bool equipFlag)
{
	if (flag)
	{
		contextMenu->clear();
		contextMenu->addAction(penColorAction);
		contextMenu->addAction(fillColorAction);
		contextMenu->addAction(backGroundAction);
		contextMenu->addAction(fontAction);
		contextMenu->addSeparator();
		contextMenu->addAction(copyAction);
		contextMenu->addAction(pasveAction);
		contextMenu->addAction(cutAction);
		contextMenu->addSeparator();
		contextMenu->addAction(arrangeAction);
		contextMenu->addAction(circumgyrateAction);
		contextMenu->addAction(fullScreenAction);	

	}
	else
	{   

		 contextMenu->clear();
		 if (equipFlag)
		 {
			 contextMenu->addAction(beckonSettingAction);
			 contextMenu->addAction(beckonSwitchAction);
		 }
		 else
		 {
			 contextMenu->addAction(updateImageAction);
			 contextMenu->addAction(fullScreenAction);
		 }
		

	}

}

void MainWindow::createToolBar()
{
	baseToolBar = addToolBar(tr("基本工具栏"));
	baseToolBar->addAction(importAction);
	baseToolBar->addAction(saveAction);	


	baseToolBar->addAction(printAction);
	baseToolBar->addSeparator();
	baseToolBar->addAction(recallAction);
	baseToolBar->addSeparator();
	baseToolBar->addAction(copyAction);
	baseToolBar->addAction(pasveAction);
	baseToolBar->addAction(cutAction);

	penWidthCombo = new QComboBox();	
	for (int i = 1; i < 21; i++)
        penWidthCombo->addItem(QString().setNum(i));
	connect(penWidthCombo, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(penWidthComBoxChanged(const QString &)));
	
	setToolBar = addToolBar(tr("图形设置工具栏"));
	setToolBar->addAction(penColorAction);
	setToolBar->addWidget(penWidthCombo);
	setToolBar->addAction(fillColorAction);	
	setToolBar->addAction(fontAction);

	
	arrangeToolBar = addToolBar(tr("排列工具栏"));
	arrangeToolBar->addAction(leftArrangeAction);
	arrangeToolBar->addAction(rihgtArrangeAction);
	arrangeToolBar->addAction(topArrangeAction);
	arrangeToolBar->addAction(bottomArrangeAction);


	stationToolBar = addToolBar(tr("站工具栏"));
	stationToolBar->addAction(stationAction);
	stationToolBar->addAction(equipAction);

	//工具栏换行
	addToolBarBreak();
	
	graphicsItemToolBar = addToolBar(tr("图元工具栏"));
	graphicsItemToolBar->addAction(selectAction);
	//graphicsItemToolBar->addAction(equipAction);
	graphicsItemToolBar->addAction(horizonalBeelineAction);
	graphicsItemToolBar->addAction(verticalBeelineAction);
	graphicsItemToolBar->addAction(rectAction);
	graphicsItemToolBar->addAction(startAction);
	graphicsItemToolBar->addAction(ellipseAction);
	graphicsItemToolBar->addAction(triangleAction);
	graphicsItemToolBar->addAction(horizonalCapacitorAction);
	graphicsItemToolBar->addAction(verticalCapacitorAction);
	graphicsItemToolBar->addAction(terminalAction);
	graphicsItemToolBar->addAction(horizonalContainerAction);
	graphicsItemToolBar->addAction(verticalContainerAction);
	graphicsItemToolBar->addAction(verticalKnivesSwitchAction);
	graphicsItemToolBar->addAction(horizonalKnivesSwitchAction);
	graphicsItemToolBar->addAction(horizonalBottomLineAction);
	graphicsItemToolBar->addAction(verticalBottomLineAction);
	graphicsItemToolBar->addAction(generatrixAction);
	graphicsItemToolBar->addAction(horizonalCurrentInductanceAction);
	graphicsItemToolBar->addAction(verticalCurrentInductanceAction);
	graphicsItemToolBar->addAction(voltageInductanceAction);
	graphicsItemToolBar->addAction(reactorAction);	
	graphicsItemToolBar->addAction(verticalBreakerAction);	
	graphicsItemToolBar->addAction(horizonalBreakerAction);	
	graphicsItemToolBar->addAction(splitReactorAction);	
	graphicsItemToolBar->addAction(reactorAction);	
	graphicsItemToolBar->addAction(transformerAction);	
	graphicsItemToolBar->addAction(transformer1Action);	
	graphicsItemToolBar->addAction(powerHouseAction);
	graphicsItemToolBar->addAction(topLineAction);
	graphicsItemToolBar->addAction(bottomLineAction);
	graphicsItemToolBar->addAction(leftLineAction);
	graphicsItemToolBar->addAction(rightLineAction);
	graphicsItemToolBar->addAction(textAction);
	
}

void MainWindow::createDock()
{

	dirTreeDock = new QDockWidget(tr("本站目录树"),this);
	dirTreeDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
	
	dirTreeWidget = new DirTreeWidget(this);
	dirTreeDock->setWidget(dirTreeWidget);
	dirTreeDock->setVisible(false);
	this->addDockWidget(Qt::LeftDockWidgetArea,dirTreeDock);

	toolBoxDock = new QDockWidget(tr("工具箱"),this);
	toolBoxDock->setMinimumWidth (160);
	toolBoxDock->setFeatures(QDockWidget::AllDockWidgetFeatures);

	toolboxWindow = new ToolboxWindow(toolBoxDock,Qt::SubWindow);
	toolBoxDock->setWidget(toolboxWindow);
	toolBoxDock->setVisible(false);
	this->addDockWidget(Qt::LeftDockWidgetArea,toolBoxDock);

}


void MainWindow::selectAllItem()
{

	scene->selectAllItem();

}

void MainWindow::otherSave()
{

  QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"),
                            "/",
                            tr("*.svg")); 
 
  scene->saveSvgFile(fileName);

  m_fileName = fileName;

  setWindowTitle(m_progName+"_"+m_fileName);

  
}

void MainWindow::open()
{

	QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                 "/",
                                                 tr("*.svg")); 
	if (fileName != "")
		scene->openXMLfile(fileName);
}


void MainWindow::save()
{

	if (m_fileName == "")
	{
		 QString fileName = QFileDialog::getSaveFileName(this, tr("保存为"),
									"/",
									tr("*.svg")); 
		 
		 scene->saveSvgFile(fileName);

		 m_fileName = fileName;

	}
	else
		 scene->saveSvgFile(m_fileName);


    setWindowTitle(m_progName+"_"+m_fileName);


}

void MainWindow::saveSCD()
{

	 QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"),
								"/",
								tr("*.scd")); 
	 
	  scene->saveScdFile(fileName);

	  m_fileName = fileName;

	  setWindowTitle(m_progName+"_"+m_fileName);

}

void MainWindow::openSCD()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                 "/",
                                                 tr("*.scd")); 
	if (fileName != "")
		scene->openSCDXMLFile(fileName);

}

void MainWindow::newEdit()
{
	m_fileName = "";
    setWindowTitle(m_progName+"_"+m_fileName);
	scene->initScene();
	view->update();
}

void MainWindow::setBackgroundColor()
{

	QColor color = QColorDialog::getColor(Qt::white, NULL);
	if (color.isValid()) {
	  scene->setBackgroundBrush(QBrush(color));
	  scene->update();
	  view->update();
	}

}

void MainWindow::setSceneSize()
{
	InputSceneSizeDialog *dlg = new InputSceneSizeDialog(this);
	if (dlg->exec()){
		int width,height;
		dlg->getWidthAndHight(&width,&height);
		scene->setSceneSize(width,height);
		view->update();
	}
	
}


void MainWindow::setMode()
{
	QAction *tmpAction = qobject_cast<QAction *>(sender());
	

	if (tmpAction == ellipseAction)
	{
		scene->setMode(DiagramScene::InsertElipase);
	}
	else if (tmpAction == startAction)
	{
		scene->setMode(DiagramScene::InsertStarry);
	}
	else if (tmpAction == rectAction)
	{
		scene->setMode(DiagramScene::InsertRectangle);
	}
	else if (tmpAction == horizonalBeelineAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalBeeline);
	}
	else if (tmpAction == verticalBeelineAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalBeeline);
	}
	else if (tmpAction == triangleAction)
	{
		scene->setMode(DiagramScene::InsertTriangle);
	}
	else if (tmpAction == horizonalCapacitorAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalCapacitor);
	}
	else if (tmpAction == verticalCapacitorAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalCapacitor);
	}
	else if (tmpAction == terminalAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalTerminal);
	}
	else if (tmpAction == horizonalContainerAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalContainer);
	}
	else if (tmpAction == verticalContainerAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalContainer);
	}
	else if (tmpAction == verticalKnivesSwitchAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalKnivesSwitch);
	}
	else if (tmpAction == horizonalKnivesSwitchAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalKnivesSwitch);
	}
	else if (tmpAction == verticalBottomLineAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalBottomLine);
	}
	else if (tmpAction == horizonalBottomLineAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalBottomLine);
	}
	else if (tmpAction == generatrixAction)
	{
		scene->setMode(DiagramScene::InsertGeneratrix);
	}
	else if (tmpAction == horizonalCurrentInductanceAction)
	{
		scene->setMode(DiagramScene::Insert_Left_CurrentInductance);
	}
	else if (tmpAction == verticalCurrentInductanceAction)
	{
		scene->setMode(DiagramScene::Insert_Right_CurrentInductance);
	}
	else if (tmpAction == voltageInductanceAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalVoltageInductance);
	}
	else if (tmpAction == verticalBreakerAction)
	{
		scene->setMode(DiagramScene::Insert_VerticalBreaker);
	}
	else if (tmpAction == horizonalBreakerAction)
	{
		scene->setMode(DiagramScene::Insert_HorizonalBreaker);
	}
	else if (tmpAction == splitReactorAction)
	{
		scene->setMode(DiagramScene::InsertSplitReactor);
	}
	else if (tmpAction == reactorAction)
	{
		scene->setMode(DiagramScene::InsertReactor);
	}
	else if (tmpAction == transformerAction)
	{
		scene->setMode(DiagramScene::InsertTransformer);
	}
	else if (tmpAction == transformer1Action)
	{
		scene->setMode(DiagramScene::Inserttransformer1);
	}
	else if (tmpAction == powerHouseAction)
	{
		scene->setMode(DiagramScene::InsertPowerHouse);
	}
	else if (tmpAction == topLineAction)
	{
		scene->setMode(DiagramScene::Insert_Top_Line);
	}
	else if (tmpAction == bottomLineAction)
	{
		scene->setMode(DiagramScene::Insert_Bottom_Line);
	}
	else if (tmpAction == leftLineAction)
	{
		scene->setMode(DiagramScene::Insert_Left_Line);
	}
	else if (tmpAction == rightLineAction)
	{
		scene->setMode(DiagramScene::Insert_Right_Line);
	}
	else if (tmpAction == selectAction)
	{
		scene->setMode(DiagramScene::SelectItem);
	}
	else if ( tmpAction == textAction)
	{
		scene->setMode(DiagramScene::InsertText);
	}
	


}


void MainWindow::setFillColor()
{

	QColor color = QColorDialog::getColor(Qt::white, NULL);
	if (color.isValid()) {
		scene->setFillColor(color);
	}

}

void MainWindow::setPenColor()
{
	QColor color = QColorDialog::getColor(Qt::white, NULL);
	if (color.isValid()) {
			scene->setPenColor(color);
	}

}

void MainWindow::setContextMenuSel()
{

	QAction *tmpAction = qobject_cast<QAction *>(sender());
	

	if (tmpAction == penColorAction){
	
		QColor color = QColorDialog::getColor(Qt::white, NULL);
		if (color.isValid()) {
			scene->setPenColor(color);
		}
		
	}else if (tmpAction == fillColorAction){
	
		QColor color = QColorDialog::getColor(Qt::white, NULL);
		if (color.isValid()) {
			scene->setFillColor(color);
		}
	}else if (tmpAction == fontAction){
	


	}

}

void MainWindow::deleteItem()
{
    foreach (QGraphicsItem *item, scene->selectedItems()) {
       
        scene->removeItem(item);
		delete item;
    }
}

void MainWindow::setAngle()
{

	angle += 90;
   
	scene->setAngle(angle);

	if (angle>=360)
		angle = 0;

}

void MainWindow::subEdit()
{

	
	QAction *senderAction = qobject_cast<QAction *>(sender());
	
	if (senderAction == equipAction)
	{
		scene->setMode(DiagramScene::Insert_Equip);
	}
	else if (senderAction == stationAction )
	{
		scene->setMode(DiagramScene::Insert_Station);
	}

}

void MainWindow::setArrange()
{

	QAction *tmpAction = qobject_cast<QAction *>(sender());
	

	if (tmpAction == leftArrangeAction)
	{

		scene->setLeftArrange();
	}
	else if (tmpAction == rihgtArrangeAction)
	{
		scene->setRightArrange();
		
	}
	else if (tmpAction == topArrangeAction)
	{
		scene->setTopArrange();
		
	}
	else if (tmpAction == bottomArrangeAction)
	{
		scene->setbottom();
		
	}


}


void MainWindow::itemCopy()
{

	scene->itemCopy();

}

void MainWindow::itemPasv()
{

	scene->itemPasve();
}

void MainWindow::setFont()
{
	bool ok;
    QFont font = QFontDialog::getFont(
                 &ok, QFont("Helvetica [Cronyx]", 10), this);
   if (ok) {							
		scene->setFont(font);
	} 

}

void MainWindow::penWidthComBoxChanged(const QString &strPenWidth)
{
	scene->setPenWidth(strPenWidth.toInt());
}

void MainWindow::setToolBoxDockVisual(bool visible)
{
	
	toolBoxDock->setVisible(visible);
}



void MainWindow::setEditShowModel(bool flag)
{
    m_Flag = flag;
	addContextMenuAction(flag,false);
	scene->setEditShowModel(flag);
}

bool MainWindow::editShowModel()
{
	return m_Flag;
}

void MainWindow::setWindowFullScreen()
{

	if (!m_fullScreenFlag)
	{
		menuBar()->hide();
		baseToolBar->hide();
		setToolBar->hide();
		arrangeToolBar->hide();
		stationToolBar->hide();
		graphicsItemToolBar->hide();
		this->showFullScreen();
		m_fullScreenFlag = true;


	}
	else
	{

		menuBar()->show();
		baseToolBar->show();
		setToolBar->show();
		arrangeToolBar->show();
		stationToolBar->show();
		graphicsItemToolBar->show();
		this->showNormal();
		m_fullScreenFlag = false;
	}

}