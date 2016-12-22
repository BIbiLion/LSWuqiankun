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
	m_progName = "SVG/SCD����ͼ�α༭ϵͳ";

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
	newAction	    = new QAction(QIcon("images/new.png"),tr("�½�(&N)"), this); 
	importAction    = new QAction(QIcon("images/open.png"),tr("��(&O)"), this);  
	importAction    = new QAction(tr("��(&O)"), this);  
    saveAction	    = new QAction(QIcon("images/save.png"),tr("����(&S)"), this);  
	otherSaveAction = new QAction(QIcon("images/save.png"),tr("���Ϊ"), this);
	saveScdAction   = new QAction(QIcon("images/save.png"),tr("����SCD"), this);
	openScdAction   = new QAction(QIcon("images/open.png"),tr("��SCD"), this);
	printAction     = new QAction(QIcon("images/print.png"),tr("��ӡ(&P)"), this);
    
	printViewAction = new QAction(tr("��ӡԤ��(&V)"), this);
	printSetAction  = new QAction(tr("��ӡ����(&R)"), this);
	exitAction      = new QAction(tr("�˳�(&X)"), this);

	recallAction    = new QAction(QIcon("images/undo.png"),tr("����(&Z)"), this); 
	copyAction      = new QAction(QIcon("images/copy.png"),tr("����(&C)"), this);  
	pasveAction     = new QAction(QIcon("images/paste.png"),tr("ճ��(&V)"), this); 
	cutAction       = new QAction(QIcon("images/cut.png"),tr("����(&X)"), this);
 
    arrangeAction      = new QAction(tr("����"), this);
	circumgyrateAction = new QAction(tr("��ת"), this);
  
	selectAllItemAction  = new QAction(tr("ѡ������ͼԪ"), this);
	selectAllEquipAction = new QAction(tr("ѡ������װ��"), this);
	
	leftArrangeAction    = new QAction(QIcon("images/left.png"),tr("�����"), this);
	rihgtArrangeAction   = new QAction(QIcon("images/right.png"),tr("�Ҷ���"), this);
	topArrangeAction     = new QAction(QIcon("images/top.png"),tr("���˶���"), this);
	bottomArrangeAction  = new QAction(QIcon("images/bottom.png"),tr("�׶˶���"), this);

	penColorAction       = new QAction(QIcon("images/pen.png"),tr("���û�����ɫ"), this);
	fillColorAction      = new QAction(QIcon("images/fill.png"),tr("���������ɫ"), this);
	sceneSizeAction      = new QAction(tr("���ó�����С"), this);
	backGroundAction     = new QAction(tr("���ó����ı���ɫ"), this);
	fontAction           = new QAction(QIcon("images/font.png"),tr("��������"), this);
	fullScreenAction     = new QAction(QIcon("images/actualsize.png"),tr("ȫ��"), this);
	updateImageAction    = new QAction(QIcon("images/actualsize.png"),tr("ˢ��ͼ��"), this);
	

	beckonSettingAction  = new QAction(tr("�ٻ���ֵ��"), this);
	beckonSwitchAction   = new QAction(tr("�ٻ�������"), this);

	toolBarAction        = new QAction(tr("������"), this);
	statusBarAction      = new QAction(tr("״̬��"), this);
	dirTreeAction        = new QAction(tr("Ŀ¼��"), this);

	stationAction                    = new QAction(QIcon("images/graphicsitem/equip.png"),tr("վ"), this);
    equipAction                      = new QAction(QIcon("images/graphicsitem/equip.png"),tr("װ��"), this);

    selectAction					 = new QAction(QIcon("images/graphicsitem/select.png"),tr("ѡ��"), this);
	horizonalBeelineAction           = new QAction(QIcon("images/graphicsitem/horizonalbeeline.png"),tr("ֱ��"), this);
	verticalBeelineAction            = new QAction(QIcon("images/graphicsitem/verticalBeeline.png"),tr("ֱ��"), this);
	rectAction                       = new QAction(QIcon("images/graphicsitem/rect.png"),tr("����"), this);
	startAction                      = new QAction(QIcon("images/graphicsitem/start.png"),tr("����"), this);
	ellipseAction                    = new QAction(QIcon("images/graphicsitem/ellipse.png"),tr("��Բ"), this);
	triangleAction                   = new QAction(QIcon("images/graphicsitem/triangle.png"),tr("������"), this);
	horizonalCapacitorAction         = new QAction(QIcon("images/graphicsitem/capacitor.png"),tr("������"), this);
	verticalCapacitorAction          = new QAction(QIcon("images/graphicsitem/capacitor.png"),tr("������"), this);
	terminalAction                   = new QAction(QIcon("images/graphicsitem/terminal.png"),tr("�ն�"), this);
	horizonalContainerAction         = new QAction(QIcon("images/graphicsitem/horizonalcontainer.png"),tr("�ݶ���"), this);
    verticalContainerAction          = new QAction(QIcon("images/graphicsitem/verticalcontainer.png"),tr("�ݶ���"), this);
	verticalKnivesSwitchAction       = new QAction(QIcon("images/graphicsitem/verticalkniveSwitch.png"),tr("��բ"), this);
	horizonalKnivesSwitchAction      = new QAction(QIcon("images/graphicsitem/horizonalkniveSwitch.png"),tr("��բ"), this);
	horizonalBottomLineAction        = new QAction(QIcon("images/graphicsitem/horizonalbottomLine.png"),tr("�ӵ���"), this);
	verticalBottomLineAction         = new QAction(QIcon("images/graphicsitem/verticalbottomLine.png"),tr("�ӵ���"), this);
	generatrixAction				 = new QAction(QIcon("images/graphicsitem/generatrix.png"),tr("ĸ��"), this);
	horizonalCurrentInductanceAction = new QAction(QIcon("images/graphicsitem/leftcurrentInductance.png"),tr("����������"), this);
	verticalCurrentInductanceAction  = new QAction(QIcon("images/graphicsitem/rightcurrentInductance.png"),tr("����������"), this);
	voltageInductanceAction          = new QAction(QIcon("images/graphicsitem/voltageInductance.png"),tr("��ѹ������"), this);
	horizonalBreakerAction           = new QAction(QIcon("images/graphicsitem/horizonalbreaker.png"),tr("��·��"), this);
	verticalBreakerAction            = new QAction(QIcon("images/graphicsitem/verticalbreaker.png"),tr("��·��"), this);
	splitReactorAction               = new QAction(QIcon("images/graphicsitem/splitReactor.png"),tr("���ѵ翹��"), this);
	reactorAction                    = new QAction(QIcon("images/graphicsitem/reactor.png"),tr("�翹��"), this);
	transformerAction                = new QAction(QIcon("images/graphicsitem/transformer.png"),tr("��ѹ��"), this);
	transformer1Action               = new QAction(QIcon("images/graphicsitem/transformer1.png"),tr("��ѹ��"), this);
	powerHouseAction                 = new QAction(QIcon("images/graphicsitem/powerHouse.png"),tr("���糧"), this);
	topLineAction                    = new QAction(QIcon("images/graphicsitem/topline.png"),tr("��·"), this);
	bottomLineAction                 = new QAction(QIcon("images/graphicsitem/bottomline.png"),tr("��·"), this);
	leftLineAction                   = new QAction(QIcon("images/graphicsitem/leftline.png"),tr("��·"), this);
	rightLineAction                  = new QAction(QIcon("images/graphicsitem/rightline.png"),tr("��·"), this);
	textAction                       = new QAction(QIcon("images/graphicsitem/text.png"),tr("�ı�"), this);
	
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
    fileMenu = menuBar()->addMenu(tr("�ļ�(&F)"));
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

    graphicsOperateMenu = menuBar()->addMenu(tr("��ͼ����(&D)"));
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

    graphicsSetMenu = menuBar()->addMenu(tr("��ͼ����(&S)"));
	graphicsSetMenu->addAction(penColorAction);
	graphicsSetMenu->addAction(fillColorAction);
	graphicsSetMenu->addSeparator();
	graphicsSetMenu->addAction(sceneSizeAction);
	graphicsSetMenu->addAction(backGroundAction);
	graphicsSetMenu->addSeparator();
	graphicsSetMenu->addAction(fontAction);
 

	viewMneu = menuBar()->addMenu(tr("�鿴(&V)"));
    viewMneu->addAction(toolBarAction);
	viewMneu->addAction(statusBarAction);
	viewMneu->addSeparator();
	viewMneu->addAction(dirTreeAction);

	helpMenu = menuBar()->addMenu(tr("����(&H)"));


	//�����ҽ��˵�
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
	baseToolBar = addToolBar(tr("����������"));
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
	
	setToolBar = addToolBar(tr("ͼ�����ù�����"));
	setToolBar->addAction(penColorAction);
	setToolBar->addWidget(penWidthCombo);
	setToolBar->addAction(fillColorAction);	
	setToolBar->addAction(fontAction);

	
	arrangeToolBar = addToolBar(tr("���й�����"));
	arrangeToolBar->addAction(leftArrangeAction);
	arrangeToolBar->addAction(rihgtArrangeAction);
	arrangeToolBar->addAction(topArrangeAction);
	arrangeToolBar->addAction(bottomArrangeAction);


	stationToolBar = addToolBar(tr("վ������"));
	stationToolBar->addAction(stationAction);
	stationToolBar->addAction(equipAction);

	//����������
	addToolBarBreak();
	
	graphicsItemToolBar = addToolBar(tr("ͼԪ������"));
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

	dirTreeDock = new QDockWidget(tr("��վĿ¼��"),this);
	dirTreeDock->setFeatures(QDockWidget::AllDockWidgetFeatures);
	
	dirTreeWidget = new DirTreeWidget(this);
	dirTreeDock->setWidget(dirTreeWidget);
	dirTreeDock->setVisible(false);
	this->addDockWidget(Qt::LeftDockWidgetArea,dirTreeDock);

	toolBoxDock = new QDockWidget(tr("������"),this);
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

  QString fileName = QFileDialog::getSaveFileName(this, tr("���Ϊ"),
                            "/",
                            tr("*.svg")); 
 
  scene->saveSvgFile(fileName);

  m_fileName = fileName;

  setWindowTitle(m_progName+"_"+m_fileName);

  
}

void MainWindow::open()
{

	QString fileName = QFileDialog::getOpenFileName(this, tr("���ļ�"),
                                                 "/",
                                                 tr("*.svg")); 
	if (fileName != "")
		scene->openXMLfile(fileName);
}


void MainWindow::save()
{

	if (m_fileName == "")
	{
		 QString fileName = QFileDialog::getSaveFileName(this, tr("����Ϊ"),
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

	 QString fileName = QFileDialog::getSaveFileName(this, tr("���Ϊ"),
								"/",
								tr("*.scd")); 
	 
	  scene->saveScdFile(fileName);

	  m_fileName = fileName;

	  setWindowTitle(m_progName+"_"+m_fileName);

}

void MainWindow::openSCD()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("���ļ�"),
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