#include<stdio.h>
#include <iostream>

/*
dateTime
*/
#define   DATE_TIME_NO_DEFAULT
#define BOOS_DATE_TIME_SOURCE
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <stdio.h>
using namespace boost::gregorian;

#include <time.h>
#include <assert.h>
int main()
{
	 date d1;  //不传参数是一个无效的时间
     std::cout<< d1.is_not_a_date();

	   date d2(2010,1,1);
	   d2.end_of_month();  //day_iterator	  month_iterator year_iterator
	   date d3(d2);

	   date	 d4=from_string("1989-12-22");//可以使用斜杠/ 或者连字符-
	   date d5=from_undelimited_string("19891222");
	   std::cout<<d2.day()<<"----"<<d4.day_of_year()<<"--------"<<d5.day_count()<<std::endl;

		//超过范围 构造函数抛出异常
		date maxDate(max_date_time);   //9999-12-31
		date minDate(min_date_time);   //1400-01-01
		
	    date::ymd_type ymd=	maxDate.year_month_day();
		std::cout<<maxDate.year();//<<"----"<<minDate.year_month_day()<<std::endl;
	
		//date转换成字符串
		std::cout<< to_simple_string(maxDate)<<"---"<<to_iso_string(minDate)<<"---"<<to_iso_extended_string(d4)<<std::endl;
		
		//支持输入输出流
		//std::cin>>d4;	 //2010-Jan-02
		std::cout<<d4;

		 //转换成time.h tm的结构体
			std::tm _t=to_tm(d4);
			d2=date_from_tm(_t);
			std::cout<<"---"<<to_simple_string(d2);

		//时长 days（date_duraion） 单位是天  ,weeks单位周；months 单位月 years 单位年
		   days dateDurationFir(-100),dateDurationSec(50);
		    (dateDurationFir > dateDurationSec);
			days _totalDuration=dateDurationSec + dateDurationFir;

		  //日期运算    日期支持 - 操作
			date _wwAdd(1989,12,22);
			 date _yrDate(1988,03,26);
			 std::cout<<"\n"<<_yrDate- _wwAdd;

			 days _duration(-636);	//weeks _weekDuration(3); years _yearDuration(1);
			//assert( _wwAdd+_duration == _yrDate) ;


			 //日期区间 date_period	  表示范围 [date1,date2) 或者 [date1,days)
			 //shift(days)左移动days   expand(days)将区域向两端分别延伸days天,相当于区间长度加2days
			date_period _dataPeriod(d4,d2);



		getchar();

	return 0;
}