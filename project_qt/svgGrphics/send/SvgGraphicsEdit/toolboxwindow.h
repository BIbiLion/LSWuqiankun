#ifndef TOOLBOXWINDOW_H
#define TOOLBOXWINDOW_H

#include <QWidget>


class QToolButton;
class QGridLayout;
class QToolBox;
class QButtonGroup;
class QAbstractButton;
class QGroupBox;
class QComboBox;

class ToolboxWindow : public QWidget
{
	Q_OBJECT

public:
	ToolboxWindow(QWidget *parent = 0);
	ToolboxWindow(QWidget * parent = 0, Qt::WindowFlags f = 0 );
	~ToolboxWindow();

private:
	
	QGridLayout		*gridLayout;
    QToolBox		*toolBox;
    QWidget			*basePage;							    //基本图元标签
	QWidget			*staticPage;						    //静态图元标签
	QWidget			*dynPage;							    //动态图元标签
	QWidget			*funSetPage;							//动态图元标签


	QToolButton		*toolButton_select;					    //用来保存当前选中的按钮

	//------------基本图元工具按钮----------------
	QToolButton		*toolButton_line_Hor;					//直线
	QToolButton		*toolButton_line_Ver;					//直线
	QToolButton		*toolButton_ellipse;				    //椭圆
	QToolButton		*toolButton_rect;					    //矩形
	QToolButton		*toolButton_text;					    //文本
	QToolButton		*toolButton_LineArrow_Top;				//箭头
	QToolButton		*toolButton_LineArrow_Bom;				//箭头
	QToolButton		*toolButton_LineArrow_Lef;				//箭头
	QToolButton		*toolButton_LineArrow_Rig;				//箭头
	QToolButton		*toolButton_thirdangle;				    //三角形
	
	//------------静态图元工具按钮----------------
	QToolButton		*toolButton_jtcompensator_Split;		//分裂电抗器
	QToolButton		*toolButton_jtbreakcompensator;		    //电抗器
	QToolButton		*toolButton_jtct_Hor;					//CT对象
	QToolButton		*toolButton_jtct_Ver;					//CT对象
	QToolButton		*toolButton_jteachfelli_Lef;			//电流互感器
	QToolButton		*toolButton_jteachfelli_Rig;			//电流互感器
	QToolButton		*toolButton_jteachfellv;			    //电压互感器
	QToolButton		*toolButton_jtground_Hor;				//接地
	QToolButton		*toolButton_jtground_Ver;				//接地
	QToolButton		*toolButton_jtinsure_Hor;				//熔断器
	QToolButton		*toolButton_jtinsure_Ver;				//熔断器
	QToolButton		*toolButton_jtstar;					    //三星形
	QToolButton		*toolButton_jtterminal;				    //终端器
	QToolButton		*toolButton_jtthunder;				    //避雷器
	
	//------------动态图元工具按钮----------------
	QToolButton		*toolButton_dtzyswitch_Hor;				//刀闸开关
	QToolButton		*toolButton_dtzyswitch_Ver;				//刀闸开关
	QToolButton		*toolButton_dtzybreaker_Hor;			//断路器
	QToolButton		*toolButton_dtzybreaker_Ver;			//断路器
	QToolButton		*toolButton_dtzyengine;				    //发电机
	QToolButton		*toolButton_dtzy2trans;				    //2圈变压器
	QToolButton		*toolButton_dtzy3trans;				    //3圈变压器
	QToolButton		*toolButton_dtzygeneratrix;			    //基本母线

	//------------功能设置按钮-------------------
    QToolButton     *toolButton_penColor;                   //画笔颜色
	QComboBox		*combox_penWidth;				        //画笔宽度
	QToolButton     *toolButton_fillColor;                  //填充颜色
	QToolButton     *boolButton_backgroundColor;            //背景色
	QToolButton     *boolButton_font;                       //字体
	QToolButton     *boolButton_sceneSize;                  //场景大小
	QToolButton     *boolButton_topArrange;                 //上对齐
	QToolButton     *boolButton_bottomArrange;              //下对齐
	QToolButton     *boolButton_leftArrange;                //左对齐
	QToolButton     *boolButton_rightArrange;               //右对齐
	QToolButton     *boolButton_editMode;                   //编辑模式
	
	

    void createWidget();
	void createBasePageBox(QWidget * parent,      QButtonGroup * baseButtonGroup);
	void createStaticPageBox(QWidget * parent,    QButtonGroup * baseButtonGroup);
	void createDynPageBox(QWidget * parent,       QButtonGroup * baseButtonGroup);
	void createFunSetPageBox(QWidget * parent);

private slots:

    void baseButtonGroupClicked(int id);
	void staticButtonGroupClicked(int id);
	void dynButtonGroupClicked(int id);
	void penWidthComBoxChanged(const QString &strPenWidth);
	void toolButtonClicked( bool checked = false );
};

#endif // TOOLBOXWINDOW_H
