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
    QWidget			*basePage;							    //����ͼԪ��ǩ
	QWidget			*staticPage;						    //��̬ͼԪ��ǩ
	QWidget			*dynPage;							    //��̬ͼԪ��ǩ
	QWidget			*funSetPage;							//��̬ͼԪ��ǩ


	QToolButton		*toolButton_select;					    //�������浱ǰѡ�еİ�ť

	//------------����ͼԪ���߰�ť----------------
	QToolButton		*toolButton_line_Hor;					//ֱ��
	QToolButton		*toolButton_line_Ver;					//ֱ��
	QToolButton		*toolButton_ellipse;				    //��Բ
	QToolButton		*toolButton_rect;					    //����
	QToolButton		*toolButton_text;					    //�ı�
	QToolButton		*toolButton_LineArrow_Top;				//��ͷ
	QToolButton		*toolButton_LineArrow_Bom;				//��ͷ
	QToolButton		*toolButton_LineArrow_Lef;				//��ͷ
	QToolButton		*toolButton_LineArrow_Rig;				//��ͷ
	QToolButton		*toolButton_thirdangle;				    //������
	
	//------------��̬ͼԪ���߰�ť----------------
	QToolButton		*toolButton_jtcompensator_Split;		//���ѵ翹��
	QToolButton		*toolButton_jtbreakcompensator;		    //�翹��
	QToolButton		*toolButton_jtct_Hor;					//CT����
	QToolButton		*toolButton_jtct_Ver;					//CT����
	QToolButton		*toolButton_jteachfelli_Lef;			//����������
	QToolButton		*toolButton_jteachfelli_Rig;			//����������
	QToolButton		*toolButton_jteachfellv;			    //��ѹ������
	QToolButton		*toolButton_jtground_Hor;				//�ӵ�
	QToolButton		*toolButton_jtground_Ver;				//�ӵ�
	QToolButton		*toolButton_jtinsure_Hor;				//�۶���
	QToolButton		*toolButton_jtinsure_Ver;				//�۶���
	QToolButton		*toolButton_jtstar;					    //������
	QToolButton		*toolButton_jtterminal;				    //�ն���
	QToolButton		*toolButton_jtthunder;				    //������
	
	//------------��̬ͼԪ���߰�ť----------------
	QToolButton		*toolButton_dtzyswitch_Hor;				//��բ����
	QToolButton		*toolButton_dtzyswitch_Ver;				//��բ����
	QToolButton		*toolButton_dtzybreaker_Hor;			//��·��
	QToolButton		*toolButton_dtzybreaker_Ver;			//��·��
	QToolButton		*toolButton_dtzyengine;				    //�����
	QToolButton		*toolButton_dtzy2trans;				    //2Ȧ��ѹ��
	QToolButton		*toolButton_dtzy3trans;				    //3Ȧ��ѹ��
	QToolButton		*toolButton_dtzygeneratrix;			    //����ĸ��

	//------------�������ð�ť-------------------
    QToolButton     *toolButton_penColor;                   //������ɫ
	QComboBox		*combox_penWidth;				        //���ʿ��
	QToolButton     *toolButton_fillColor;                  //�����ɫ
	QToolButton     *boolButton_backgroundColor;            //����ɫ
	QToolButton     *boolButton_font;                       //����
	QToolButton     *boolButton_sceneSize;                  //������С
	QToolButton     *boolButton_topArrange;                 //�϶���
	QToolButton     *boolButton_bottomArrange;              //�¶���
	QToolButton     *boolButton_leftArrange;                //�����
	QToolButton     *boolButton_rightArrange;               //�Ҷ���
	QToolButton     *boolButton_editMode;                   //�༭ģʽ
	
	

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
