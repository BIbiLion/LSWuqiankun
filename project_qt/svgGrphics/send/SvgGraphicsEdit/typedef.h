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
	
	//先注册DirStruct,Qvariant还不认识这个类型,这是一个Macro--只能在全局中使用--否则出现错误。
    Q_DECLARE_METATYPE(DirStruct)
#endif



#define BELLLINE_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 100           //直线
#define BELLLINE_VERTICAL_GRAPHICSITEM				    QVariant::UserType + 101           //直线
#define RECTANGLE_GRAPHICSITEM							QVariant::UserType + 102           //矩形
#define STARRY_GRAPHICSITEM								QVariant::UserType + 103           //星形
#define ELLIPSE_GRAPHICSITEM							QVariant::UserType + 104           //椭圆
#define TRIANGLE_GRAPHICSITEM							QVariant::UserType + 105           //三角形
#define CAPACTIOR_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 106           //电容器
#define CAPACTIOR_VERTICAL_GRAPHICSITEM					QVariant::UserType + 107           //电容器
#define TERMINAL_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 108           //终端
#define TERMINAL_VERTICAL_GRAPHICSITEM					QVariant::UserType + 109           //终端
#define CONTAINER_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 110           //容断器
#define CONTAINER_VERTICAL_GRAPHICSITEM					QVariant::UserType + 111           //容断器
#define KNIVESSWITCH_HORIZONTAL_GRAPHICSITEM			QVariant::UserType + 112           //刀闸
#define KNIVESSWITCH_VERTICALL_GRAPHICSITEM				QVariant::UserType + 113           //刀闸
#define BOTTOMLINE_HORIZONTAL_GRAPHICSITEM				QVariant::UserType + 114           //接地线
#define BOTTOMLINE_VERTICALL_GRAPHICSITEM				QVariant::UserType + 115           //接地线
#define GENERATRIX_GRAPHICSITEM							QVariant::UserType + 116           //母线 
#define CURRENTINDUCTANCE_LEFT_GRAPHICSITEM             QVariant::UserType + 117           //电流互感器
#define CURRENTINDUCTANCE_RIGHT_GRAPHICSITEM			QVariant::UserType + 118		   //电流互感器
#define VOLTAGEINDUCTANCE_HORIZONTAL_GRAPHICSITEM		QVariant::UserType + 119		   //电压互感器
#define VOLTAGEINDUCTANCE_VERTICALL_GRAPHICSITEM		QVariant::UserType + 120		   //电压互感器
#define BREAKER_HORIZONTAL_GRAPHICSITEM					QVariant::UserType + 121           //断路器
#define BREAKER_VERTICAL_GRAPHICSITEM					QVariant::UserType + 122           //断路器
#define SPLITREACTOR_GRAPHICSITEM						QVariant::UserType + 123		   //分裂电抗器
#define REACTOR_GRAPHICSITEM							QVariant::UserType + 124           //电抗器
#define TRANSFORMER_GRAPHICSITEM						QVariant::UserType + 125           //三芯变压器
#define TRANSFORMER1_GRAPHICSITEM						QVariant::UserType + 126           //二芯变压器
#define POWERHOUSE_GRAPHICSITEM							QVariant::UserType + 127           //发电厂
#define LINE_TOP_GRAPHICSITEM							QVariant::UserType + 128           //线路
#define LINE_BUTTOM_GRAPHICSITEM					    QVariant::UserType + 129           //线路
#define LINE_LEFT_GRAPHICSITEM					        QVariant::UserType + 130           //线路
#define LINE_RIGHT_GRAPHICSITEM					        QVariant::UserType + 131           //线路
#define TEXT_GRAPHICSITEM								QVariant::UserType + 132           //文本
#define EQUIP_GRAPHICSITEM								QVariant::UserType + 133           //装置
#define STATION_GRAPHICSITEM                            QVariant::UserType + 134           //站




#endif