#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QAction;
class QTreeWidget;
class DirTreeWidget;
class DiagramScene;
class QGraphicsView;
class QLineEdit;
class QComboBox;
class ItemGraphicsView;
class ToolboxWindow;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = NULL);
	~MainWindow();

	static MainWindow * m_self;

private:
	QMenu *fileMenu;                //文件菜单
    QMenu *graphicsOperateMenu;     //画图菜单 
    QMenu *graphicsSetMenu;         //画图设置菜单
	QMenu *viewMneu;                //查看菜单
	QMenu *helpMenu;                //帮助菜单
	QMenu *contextMenu;             //右键菜单

	QAction *newAction;             //新建
    QAction *importAction;          //打开
	QAction *saveAction;            //保存
	QAction *otherSaveAction;       //保存
	QAction *saveScdAction;         //保存SCD
	QAction *openScdAction;         //打开SCD
    QAction *printAction;           //打印
	QAction *printViewAction;       //打印预览
	QAction *printSetAction;        //打印设置
	QAction *exitAction;            //退出

	QAction *recallAction;          //撤消
	QAction *copyAction;            //复制
	QAction *pasveAction;           //粘贴
	QAction *cutAction;             //剪切
	QAction *arrangeAction;         //排列
	QAction *circumgyrateAction;    //旋转
	QAction *selectAllItemAction;   //选中所有图元
	QAction *selectAllEquipAction;  //选中所有装置
	QAction *leftArrangeAction;     //左靠齐
	QAction *rihgtArrangeAction;    //右靠齐
	QAction *topArrangeAction;      //顶靠齐
	QAction *bottomArrangeAction;   //底靠齐

	QAction *beckonSettingAction;   //
	QAction *beckonSwitchAction;


	QAction *penColorAction;        //设置画笔颜色
	QAction *fillColorAction;       //设置填充颜色
	QAction *sceneSizeAction;       //设置场景大小
	QAction *backGroundAction;      //设置场景的背景色
	QAction *fontAction;            //设置字体
	
	QAction *stationAction;         //站
	QAction *equipAction;           //装置

	QAction *selectAction;                    //选择
	QAction *horizonalBeelineAction;          //直线
	QAction *verticalBeelineAction;           //直线
	QAction *rectAction;                      //矩形
	QAction *startAction;                     //星型
	QAction *ellipseAction;                   //椭圆
	QAction *triangleAction;                  //三角形
	QAction *horizonalCapacitorAction;        //电容器
	QAction *verticalCapacitorAction;         //电容器
	QAction *terminalAction;                  //终端 
	QAction *horizonalContainerAction;        //容断器
	QAction *verticalContainerAction;         //容断器
	QAction *horizonalKnivesSwitchAction;     //刀闸
	QAction *verticalKnivesSwitchAction;      //刀闸
	QAction *horizonalBottomLineAction;       //接地线
	QAction *verticalBottomLineAction;        //接地线
	QAction *generatrixAction;                //母线
	QAction *horizonalCurrentInductanceAction;//电流互感器
	QAction *verticalCurrentInductanceAction; //电流互感器
	QAction *voltageInductanceAction;         //电压互感器
	QAction *horizonalBreakerAction;          //断路器
	QAction *verticalBreakerAction;           //断路器
	QAction *splitReactorAction;              //分裂电抗器
	QAction *reactorAction;                   //电抗器
	QAction *transformerAction;               //三芯变压器
	QAction *transformer1Action;              //二芯变压器
	QAction *powerHouseAction;                //发电厂
	QAction *topLineAction;                   //线路
	QAction *bottomLineAction;                //线路
	QAction *leftLineAction;                  //线路
	QAction *rightLineAction;                 //线路
	QAction *textAction;                      //文本

	QAction *toolBarAction;					  //工具栏
	QAction *statusBarAction;				  //状态栏
	QAction *dirTreeAction;					  //目录树
	QAction *fullScreenAction;                //全屏幕   
	QAction *updateImageAction;               //刷新图形

	QToolBar *baseToolBar;
	QToolBar *setToolBar;
	QToolBar *arrangeToolBar;
	QToolBar *stationToolBar;
	QToolBar *graphicsItemToolBar;

	QDockWidget      *dirTreeDock;
	DirTreeWidget    *dirTreeWidget;
	QComboBox        *penWidthCombo;             //笔宽度

	QDockWidget      *toolBoxDock;
	ToolboxWindow    *toolboxWindow;

	ItemGraphicsView *view;
	bool             m_fullScreenFlag;
	
	qreal            angle; 
	QString          m_fileName;
	QString          m_progName;
	
	void createAction();
	void createMenus();
	void createToolBar();
	void createDock();
	void initWidget();
	void initVar();

public:

	DiagramScene     *scene;
	QLineEdit	     *m_textEdit;			               //用来输入文本对象的文本编辑框
	bool             m_Flag;                               //true为编辑模式,false为显示模式　

	void showTextEdit (QPointF & pos,bool flag);
	void setTextEdit(QString str);

	void setToolBoxDockVisual(bool visible);
	void setEditShowModel(bool flag); 
	bool editShowModel();
	void addContextMenuAction(bool flag,bool equipFlag);

public slots:

	void newEdit();
	void open();
	void save();
	void otherSave();
	void saveSCD();
	void openSCD();
	void setFillColor();
	void setPenColor();
	void setBackgroundColor();
	void setSceneSize();
	void setMode();
	void setContextMenuSel();
	void deleteItem();	
	void selectAllItem();
	void setAngle();
	void setArrange();
	void setWindowFullScreen();
	void subEdit();
	void itemCopy();
	void itemPasv();
	void setFont();
	void penWidthComBoxChanged(const QString &strPenWidth);
};

#endif // MAINWINDOW_H
