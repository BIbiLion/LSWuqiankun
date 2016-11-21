#include "boosttime.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <sstream>
#include <assert.h>

#include <QDebug>

#include <Boost/timer.hpp>
#include <boost/progress.hpp>	 
#include <boost/assert.hpp>

using namespace boost;


//�����������   ��ʹ��ģ�����
template <int N=2>
 class 	 new_Progress_time	:public timer
{
public:
   			 new_Progress_time( std::ostream & os= std::cout)
				 :m_os(os)
			 {
					//����C++
					// assert(N<0 || N>10);
					 //boost
					// BOOST_STATIC_ASSERT()
			 }		;

			~ new_Progress_time()
			{
				try
				{
					//��������״̬
					std::istream ::fmtflags oldFlag=m_os.setf(std::istream::fixed,std::istream::floatfield)	;
					std::streamsize old_pre=m_os.precision(N);

					m_os<<elapsed();


					//	�ָ�״̬��
					m_os.flags(oldFlag);
					m_os.precision(old_pre);
				}
				catch (...)
				{
					
				}

			} ;

 private:
	 std::ostream & m_os;
 };
 
 //ģ���ػ�
 template <>
 class 	 new_Progress_time<2>	:public progress_timer
 {
 };


  void boostTime::FunctionCostTime()
 {
	 {
		 boost::progress_timer _progressTime;	 //�����������Լ�������������ѵ�ʱ��
		 qDebug()<<"FunctionCostTime----";
		 // Sleep(1000);

		 for (int i=0;i<100000;++i);
		qDebug()<< _progressTime.elapsed();	 
	 }
	
	 std::stringstream ss;
	 {
		 boost::progress_timer _outputStrStream(ss);   //�����stringstream	 
	 }
	 qDebug()<<QString(ss.str().c_str());  
	
 }

boostTime::boostTime(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

   //C++'s costTime
	clock_t begin,end;
	begin= clock();
	Sleep(1000);
	end=clock();
	qDebug()<<"cost Time:"<< (double)(end-begin)/CLOCKS_PER_SEC;


	//boost costtTime
	boost::timer _t;
	qDebug()<<	_t.elapsed_max();
	qDebug() <<	_t.elapsed_min();
	qDebug() <<	_t.elapsed();
	_t.restart();
	qDebug() <<	_t.elapsed();
		

	//progressTime���㺯����ʹ��ʱ�� һ���������ܲ���
	int _step=0;
	while (_step<20)
	 {	
		 FunctionCostTime();
	     _step++;
	  }
	

	//new_progress_timer �ྫ����

	new_Progress_time<> _newProgerssTime;
	 std::stringstream ss;
	{
		
		new_Progress_time<3> _newProgerssTime_3Precion(ss);
		//Sleep(10340);
	}
		 qDebug()<<"3Precious "<<QString(ss.str().c_str());
	
	//new_Progress_time<-1> _newProgerssTime_nonePrecion(ss);		  ���Դ���

	//�ڿ���̨��ʾִ�н���


}

boostTime::~boostTime()
{

}
