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
	QMenu *fileMenu;                //�ļ��˵�
    QMenu *graphicsOperateMenu;     //��ͼ�˵� 
    QMenu *graphicsSetMenu;         //��ͼ���ò˵�
	QMenu *viewMneu;                //�鿴�˵�
	QMenu *helpMenu;                //�����˵�
	QMenu *contextMenu;             //�Ҽ��˵�

	QAction *newAction;             //�½�
    QAction *importAction;          //��
	QAction *saveAction;            //����
	QAction *otherSaveAction;       //����
	QAction *saveScdAction;         //����SCD
	QAction *openScdAction;         //��SCD
    QAction *printAction;           //��ӡ
	QAction *printViewAction;       //��ӡԤ��
	QAction *printSetAction;        //��ӡ����
	QAction *exitAction;            //�˳�

	QAction *recallAction;          //����
	QAction *copyAction;            //����
	QAction *pasveAction;           //ճ��
	QAction *cutAction;             //����
	QAction *arrangeAction;         //����
	QAction *circumgyrateAction;    //��ת
	QAction *selectAllItemAction;   //ѡ������ͼԪ
	QAction *selectAllEquipAction;  //ѡ������װ��
	QAction *leftArrangeAction;     //����
	QAction *rihgtArrangeAction;    //�ҿ���
	QAction *topArrangeAction;      //������
	QAction *bottomArrangeAction;   //�׿���

	QAction *beckonSettingAction;   //
	QAction *beckonSwitchAction;


	QAction *penColorAction;        //���û�����ɫ
	QAction *fillColorAction;       //���������ɫ
	QAction *sceneSizeAction;       //���ó�����С
	QAction *backGroundAction;      //���ó����ı���ɫ
	QAction *fontAction;            //��������
	
	QAction *stationAction;         //վ
	QAction *equipAction;           //װ��

	QAction *selectAction;                    //ѡ��
	QAction *horizonalBeelineAction;          //ֱ��
	QAction *verticalBeelineAction;           //ֱ��
	QAction *rectAction;                      //����
	QAction *startAction;                     //����
	QAction *ellipseAction;                   //��Բ
	QAction *triangleAction;                  //������
	QAction *horizonalCapacitorAction;        //������
	QAction *verticalCapacitorAction;         //������
	QAction *terminalAction;                  //�ն� 
	QAction *horizonalContainerAction;        //�ݶ���
	QAction *verticalContainerAction;         //�ݶ���
	QAction *horizonalKnivesSwitchAction;     //��բ
	QAction *verticalKnivesSwitchAction;      //��բ
	QAction *horizonalBottomLineAction;       //�ӵ���
	QAction *verticalBottomLineAction;        //�ӵ���
	QAction *generatrixAction;                //ĸ��
	QAction *horizonalCurrentInductanceAction;//����������
	QAction *verticalCurrentInductanceAction; //����������
	QAction *voltageInductanceAction;         //��ѹ������
	QAction *horizonalBreakerAction;          //��·��
	QAction *verticalBreakerAction;           //��·��
	QAction *splitReactorAction;              //���ѵ翹��
	QAction *reactorAction;                   //�翹��
	QAction *transformerAction;               //��о��ѹ��
	QAction *transformer1Action;              //��о��ѹ��
	QAction *powerHouseAction;                //���糧
	QAction *topLineAction;                   //��·
	QAction *bottomLineAction;                //��·
	QAction *leftLineAction;                  //��·
	QAction *rightLineAction;                 //��·
	QAction *textAction;                      //�ı�

	QAction *toolBarAction;					  //������
	QAction *statusBarAction;				  //״̬��
	QAction *dirTreeAction;					  //Ŀ¼��
	QAction *fullScreenAction;                //ȫ��Ļ   
	QAction *updateImageAction;               //ˢ��ͼ��

	QToolBar *baseToolBar;
	QToolBar *setToolBar;
	QToolBar *arrangeToolBar;
	QToolBar *stationToolBar;
	QToolBar *graphicsItemToolBar;

	QDockWidget      *dirTreeDock;
	DirTreeWidget    *dirTreeWidget;
	QComboBox        *penWidthCombo;             //�ʿ��

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
	QLineEdit	     *m_textEdit;			               //���������ı�������ı��༭��
	bool             m_Flag;                               //trueΪ�༭ģʽ,falseΪ��ʾģʽ��

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
