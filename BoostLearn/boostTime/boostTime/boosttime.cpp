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


//增大输出精度   ，使用模板参数
template <int N=2>
 class 	 new_Progress_time	:public timer
{
public:
   			 new_Progress_time( std::ostream & os= std::cout)
				 :m_os(os)
			 {
					//断言C++
					// assert(N<0 || N>10);
					 //boost
					// BOOST_STATIC_ASSERT()
			 }		;

			~ new_Progress_time()
			{
				try
				{
					//保存流的状态
					std::istream ::fmtflags oldFlag=m_os.setf(std::istream::fixed,std::istream::floatfield)	;
					std::streamsize old_pre=m_os.precision(N);

					m_os<<elapsed();


					//	恢复状态流
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
 
 //模板特化
 template <>
 class 	 new_Progress_time<2>	:public progress_timer
 {
 };


  void boostTime::FunctionCostTime()
 {
	 {
		 boost::progress_timer _progressTime;	 //出了作用域，自己析构，输出花费的时间
		 qDebug()<<"FunctionCostTime----";
		 // Sleep(1000);

		 for (int i=0;i<100000;++i);
		qDebug()<< _progressTime.elapsed();	 
	 }
	
	 std::stringstream ss;
	 {
		 boost::progress_timer _outputStrStream(ss);   //输出到stringstream	 
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
		

	//progressTime计算函数的使用时间 一般用于性能测试
	int _step=0;
	while (_step<20)
	 {	
		 FunctionCostTime();
	     _step++;
	  }
	

	//new_progress_timer 多精度类

	new_Progress_time<> _newProgerssTime;
	 std::stringstream ss;
	{
		
		new_Progress_time<3> _newProgerssTime_3Precion(ss);
		//Sleep(10340);
	}
		 qDebug()<<"3Precious "<<QString(ss.str().c_str());
	
	//new_Progress_time<-1> _newProgerssTime_nonePrecion(ss);		  断言错误

	//在控制台显示执行进度


}

boostTime::~boostTime()
{

}
