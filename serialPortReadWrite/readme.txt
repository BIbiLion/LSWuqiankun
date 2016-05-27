qextserialport-1.2win-alpha.zip  是一个第三方的读写端口的文件。

他们的继承关系：
windows:    QIOdevice ---->QextSerialBase------->Win_QexSerialPort--------->QextBaseType
Linux:      QIOdevice ---->QextSerialBase------->posix_QexSerialPort--------->QextBaseType


我们在windows下只需要使用其中的6个文件：

qextserialbase.cpp和qextserialbase.h，qextserialport.cpp和qextserialport.h，win_qextserialport.cpp和win_qextserialport.h



Linux下只需将win_qextserialport.cpp和win_qextserialport.h 换为 posix_qextserialport.cpp和posix_qextserialport.h即可。