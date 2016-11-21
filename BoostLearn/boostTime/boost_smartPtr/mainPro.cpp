#include <iostream>
#include <stdio.h>
#include <assert.h>

#include <boost/enable_shared_from_this.hpp>

#include <boost\pool\pool.hpp>//内存池 pool

#include <boost\pool\object_pool.hpp>//对象的内存池
#define  RequisedSize 10
using namespace boost;



//tools 

//1. 继承 noncopyable =（约等于）  私有化 拷贝构造函数和 赋值函数
class Stu :public boost::noncopyable
{

};

//2.  C++0x typeof auto ，boost BOOST_TYPEOF BOOST_AUTO 对声明很长很长的一种解决办法  , c++编译器在编译时 自动推导 表达式的类型
#include <boost\typeof\typeof.hpp>
#include <map>

std::map<std::string,std::string> _map;
std::map<std::string,std::string>::iterator _pos=_map.begin();
//boost		  支持C++内置的基本类型 和STL中的大多数类型
 BOOST_TYPEOF(_map.begin())  pos=	_map.begin();		 //pos的类型是
 BOOST_AUTO(posauto ,   _map.begin());	//posauto的类型是 

 //自定义类型  typeof支持 的话，需要向typeof库注册类型
#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()
	  struct Company 
	  {
		  int a,b;
	  };
	BOOST_TYPEOF_REGISTER_TYPE(Company);



#include <boost\logic\tribool.hpp>
	 BOOST_TRIBOOL_THIRD_STATE(unkown);	   //	实质上定义一个函数 ，C++不允许函数嵌套，函数名

int main()
{
	//普通数据类型  ，只分配内存，不调用对象的构造函数
	{
		   pool<> p1(sizeof(int));//参数每次申请的内存大小		 pool<>只能用于普通数据类型	 int double 等
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

	//	复杂的类和对象		  object_pool
	{

	}



	//通过注册 自定义的类 来进行typeof
	BOOST_AUTO(_comMap,std::make_pair("ACompany",Company()));
	std::cout<<typeid(_comMap).name();
	getchar();


	  


		  	 return 0;
}