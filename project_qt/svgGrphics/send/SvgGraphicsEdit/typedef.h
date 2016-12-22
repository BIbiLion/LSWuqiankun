#ifndef MYTYPEDEF_H
#define MYTYPEDEF_H


#include <QVariant>

#ifndef __DirStruct__
#define __DirStruct__

	enum fillType{STATION,LINE,EQUIP};
		typedef struct {
		int staId;
		QString staName;
		int lineId;
		QString lineName;
		int equipId;
		QString equipName;
		int type;
    }DirStruct;
	
	//��ע��DirStruct,Qvariant������ʶ�������,����һ��Macro--ֻ����ȫ����ʹ��--������ִ���
    Q_DECLARE_METATYPE(DirStruct)
#endif



#define BELLLINE_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 100           //ֱ��
#define BELLLINE_VERTICAL_GRAPHICSITEM				    QVariant::UserType + 101           //ֱ��
#define RECTANGLE_GRAPHICSITEM							QVariant::UserType + 102           //����
#define STARRY_GRAPHICSITEM								QVariant::UserType + 103           //����
#define ELLIPSE_GRAPHICSITEM							QVariant::UserType + 104           //��Բ
#define TRIANGLE_GRAPHICSITEM							QVariant::UserType + 105           //������
#define CAPACTIOR_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 106           //������
#define CAPACTIOR_VERTICAL_GRAPHICSITEM					QVariant::UserType + 107           //������
#define TERMINAL_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 108           //�ն�
#define TERMINAL_VERTICAL_GRAPHICSITEM					QVariant::UserType + 109           //�ն�
#define CONTAINER_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 110           //�ݶ���
#define CONTAINER_VERTICAL_GRAPHICSITEM					QVariant::UserType + 111           //�ݶ���
#define KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM			QVariant::UserType + 112           //��բ
#define KNIVESSWITCH_VERTICALL_GRAPHICSITEM				QVariant::UserType + 113           //��բ
#define BOTTOMLINE_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 114           //�ӵ���
#define BOTTOMLINE_VERTICALL_GRAPHICSITEM				QVariant::UserType + 115           //�ӵ���
#define GENERATRIX_GRAPHICSITEM							QVariant::UserType + 116           //ĸ�� 
#define CURRENTINDUCTANCE_LEFT_GRAPHICSITEM             QVariant::UserType + 117           //����������
#define CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM			QVariant::UserType + 118		   //����������
#define VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM		QVariant::UserType + 119		   //��ѹ������
#define VOLTAGEINDUCTANCE_VERTICALL_GRAPHICSITEM		QVariant::UserType + 120		   //��ѹ������
#define BREAKER_HORIZONTAL_GRAPHICSITEM					QVariant::UserType + 121           //��·��
#define BREAKER_VERTICAL_GRAPHICSITEM					QVariant::UserType + 122           //��·��
#define SPLITREACTOR_GRAPHICSITEM						QVariant::UserType + 123		   //���ѵ翹��
#define REACTOR_GRAPHICSITEM							QVariant::UserType + 124           //�翹��
#define TRANSFORMER_GRAPHICSITEM						QVariant::UserType + 125           //��о��ѹ��
#define TRANSFORMER1_GRAPHICSITEM						QVariant::UserType + 126           //��о��ѹ��
#define POWERHOUSE_GRAPHICSITEM							QVariant::UserType + 127           //���糧
#define LINE_TOP_GRAPHICSITEM							QVariant::UserType + 128           //��·
#define LINE_BUTTOM_GRAPHICSITEM					    QVariant::UserType + 129           //��·
#define LINE_LEFT_GRAPHICSITEM					        QVariant::UserType + 130           //��·
#define LINE_RIGHT_GRAPHICSITEM					        QVariant::UserType + 131           //��·
#define TEXT_GRAPHICSITEM								QVariant::UserType + 132           //�ı�
#define EQUIP_GRAPHICSITEM								QVariant::UserType + 133           //װ��
#define STATION_GRAPHICSITEM                            QVariant::UserType + 134           //վ




#endif