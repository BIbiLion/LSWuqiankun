#include <iostream>
#include <stdio.h>
#include <assert.h>

#include <boost/enable_shared_from_this.hpp>

#include <boost\pool\pool.hpp>//�ڴ�� pool

#include <boost\pool\object_pool.hpp>//������ڴ��
#define  RequisedSize 10
using namespace boost;



//tools 

//1. �̳� noncopyable =��Լ���ڣ�  ˽�л� �������캯���� ��ֵ����
class Stu :public boost::noncopyable
{

};

//2.  C++0x typeof auto ��boost BOOST_TYPEOF BOOST_AUTO �������ܳ��ܳ���һ�ֽ���취  , c++�������ڱ���ʱ �Զ��Ƶ� ���ʽ������
#include <boost\typeof\typeof.hpp>
#include <map>

std::map<std::string,std::string> _map;
std::map<std::string,std::string>::iterator _pos=_map.begin();
//boost		  ֧��C++���õĻ������� ��STL�еĴ��������
 BOOST_TYPEOF(_map.begin())  pos=	_map.begin();		 //pos��������
 BOOST_AUTO(posauto ,   _map.begin());	//posauto�������� 

 //�Զ�������  typeof֧�� �Ļ�����Ҫ��typeof��ע������
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
	  struct Company 
	  {
		  int a,b;
	  };
	BOOST_TYPEOF_REGISTER_TYPE(Company);



#include <boost\logic\tribool.hpp>
	 BOOST_TRIBOOL_THIRD_STATE(unkown);	   //	ʵ���϶���һ������ ��C++��������Ƕ�ף�������

int main()
{
	//��ͨ��������  ��ֻ�����ڴ棬�����ö���Ĺ��캯��
	{
		   pool<> p1(sizeof(int));//����ÿ��������ڴ��С		 pool<>ֻ��������ͨ��������	 int double ��
		   int * ptr =(int *)p1.malloc();
		   if (ptr !=NULL)
		   {
			   assert(p1.is_from(ptr));

			   p1.free(ptr);

			   for(int i=0; i<100; ++i)
			   {
				   p1.ordered_malloc(RequisedSize );
			   }
		   }
	}

	//	���ӵ���Ͷ���		  object_pool
	{

	}



	//ͨ��ע�� �Զ������ ������typeof
	BOOST_AUTO(_comMap,std::make_pair("ACompany",Company()));
	std::cout<<typeid(_comMap).name();
	getchar();


	  


		  	 return 0;
}