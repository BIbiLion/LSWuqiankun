//test the 模板特化不调用标准库的文件，调用写的文件
//boost std   swap 都是用自定的函数
//代码对齐  ctrl +a  +k   +f
#include <iostream>
#include <stdio.h>

#include <boost/swap.hpp>
using namespace boost;
class  MPoint
{

public:
	MPoint(int a=0,int b=0,int c=0):x(a),y(b),z(c){};
	~ MPoint(){};

	void print()
	{
		std::cout<<x<<y<<z<<"\n";
	}

	//1重写 替换的函数
	void swap(MPoint & p)
	{
	   std::cout<<"enter point self-define swap "<<"\n";
		std::swap(x,p.x);
		std::swap(y,p.y);
		std::swap(z,p.z);
	
	}


private:
	int x,y,z;
};


//std::swap   模板特化
namespace std
{
	template<>
	void swap(MPoint & x,MPoint &y)
	{
		std::cout<<"enter std  template special function \n";
		x.swap(y);	//自定义函数
	}
}

int main()
{
	   MPoint a(1,2,3),b(4,5,6);
	   std::cout<<"std::swap"<<"\n";
	   std::swap(a,b);


	    std::cout<<"boost::swap"<<"\n";
	   boost::swap(a,b);

	   getchar();

}