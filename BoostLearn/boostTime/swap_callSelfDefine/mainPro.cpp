//test the ģ���ػ������ñ�׼����ļ�������д���ļ�
//boost std   swap �������Զ��ĺ���
//�������  ctrl +a  +k   +f
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

	//1��д �滻�ĺ���
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


//std::swap   ģ���ػ�
namespace std
{
	template<>
	void swap(MPoint & x,MPoint &y)
	{
		std::cout<<"enter std  template special function \n";
		x.swap(y);	//�Զ��庯��
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