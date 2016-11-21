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
	 date d1;  //����������һ����Ч��ʱ��
     std::cout<< d1.is_not_a_date();

	   date d2(2010,1,1);
	   d2.end_of_month();  //day_iterator	  month_iterator year_iterator
	   date d3(d2);

	   date	 d4=from_string("1989-12-22");//����ʹ��б��/ �������ַ�-
	   date d5=from_undelimited_string("19891222");
	   std::cout<<d2.day()<<"----"<<d4.day_of_year()<<"--------"<<d5.day_count()<<std::endl;

		//������Χ ���캯���׳��쳣
		date maxDate(max_date_time);   //9999-12-31
		date minDate(min_date_time);   //1400-01-01
		
	    date::ymd_type ymd=	maxDate.year_month_day();
		std::cout<<maxDate.year();//<<"----"<<minDate.year_month_day()<<std::endl;
	
		//dateת�����ַ���
		std::cout<< to_simple_string(maxDate)<<"---"<<to_iso_string(minDate)<<"---"<<to_iso_extended_string(d4)<<std::endl;
		
		//֧�����������
		//std::cin>>d4;	 //2010-Jan-02
		std::cout<<d4;

		 //ת����time.h tm�Ľṹ��
			std::tm _t=to_tm(d4);
			d2=date_from_tm(_t);
			std::cout<<"---"<<to_simple_string(d2);

		//ʱ�� days��date_duraion�� ��λ����  ,weeks��λ�ܣ�months ��λ�� years ��λ��
		   days dateDurationFir(-100),dateDurationSec(50);
		    (dateDurationFir > dateDurationSec);
			days _totalDuration=dateDurationSec + dateDurationFir;

		  //��������    ����֧�� - ����
			date _wwAdd(1989,12,22);
			 date _yrDate(1988,03,26);
			 std::cout<<"\n"<<_yrDate- _wwAdd;

			 days _duration(-636);	//weeks _weekDuration(3); years _yearDuration(1);
			//assert( _wwAdd+_duration == _yrDate) ;


			 //�������� date_period	  ��ʾ��Χ [date1,date2) ���� [date1,days)
			 //shift(days)���ƶ�days   expand(days)�����������˷ֱ�����days��,�൱�����䳤�ȼ�2days
			date_period _dataPeriod(d4,d2);



		getchar();

	return 0;
}