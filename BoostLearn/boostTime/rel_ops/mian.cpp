//res_ops   <  <=  !=  
//ʹ��res_ops���Ա��� ������� ,
//�����û����Լ��������������������� ������(��������)���Ϳ��Է�����Զ����������Ĳ�������
#include <iostream>
#include <utility>

class Foo {
	public:
	int n;
   //1				//��Ȼ����ֻ������==��<������ϵ����������ʹ�������ռ�rel_ops�����Եõ�6����
	bool operator==( const Foo& rhs)  const
	{
		return this->n == rhs.n;
	}
	
	bool operator<( const Foo& rhs)	const
	{
	return this->n < rhs.n;
	}

};


//2
/*
bool operator==(const Foo& lhs, const Foo& rhs)
{
	return lhs.n == rhs.n;
}

bool operator<(const Foo& lhs, const Foo& rhs)
{
	return lhs.n < rhs.n;
}
  */

#include <boost/lexical_cast.hpp>
	//lexical  ������ �ʻ�	ʵ�� �ַ���������֮���ת��
#include <boost/tokenizer.hpp>
#include <boost\typeof\typeof.hpp>

template<typename T>
bool num_vaild(const char * str)
{
	try
	{
		boost::lexical_cast<T>(str);
		return true	 ;
	}
	
	catch (boost::bad_lexical_cast & e)
	{
		return false;
	}
}

#include <assert.h>
int main()
{
	Foo f1 = {1};
	Foo f2 = {2};
	using namespace std::rel_ops;	 //һ�²��������Զ������ˣ�ʹ����������ռ�

	std::cout << std::boolalpha;		 //���ñ�־,��� true flase 
	std::cout << "not equal?     : " << (f1 != f2) << '\n';
	std::cout << "greater?       : " << (f1 > f2) << '\n';
	std::cout << "less equal?    : " << (f1 <= f2) << '\n';
	std::cout << "greater equal? : " << (f1 >= f2) << '\n';
	getchar();

  //���ֺ��ַ�����ת��	std::stringstream boost::formate  (�߼��ĸ�ʽ)
	std::cout	<< boost::lexical_cast<std::string> (0x10)	 <<std::endl;
	std::cout	<< boost::lexical_cast<int> ("20097610")	 <<std::endl;
	 std::cout	<< boost::lexical_cast<bool> ("0")	 <<std::endl;// bool ֻ�� 0 1
	 //����ת�����׳��쳣

	 try
	 {
		  std::cout	<< boost::lexical_cast<bool> ("2")	 <<std::endl;
	 }
	 catch (boost::bad_lexical_cast &e)
	 {
		 std::cout<<"error:"<<e.what();
	 }

	 getchar();
	 //����ת�� ������ num_valid()�����ж��Ƿ��ܽ���ת��
	std::cout<<" num can convert or No:"<< num_vaild<double>("ll");

	std::string str("name sex age");
	   boost::tokenizer<> tok(str);
	   for ( BOOST_AUTO(pos,tok.begin()) ; pos != tok.end(); ++pos)
	   {
		   std::cout<<"    "<<*pos<<    typeid(pos).name();
	   }
	getchar();

	getchar();
}




