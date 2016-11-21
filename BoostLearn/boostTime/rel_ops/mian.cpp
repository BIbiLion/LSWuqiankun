//res_ops   <  <=  !=  
//使用res_ops可以避免 多次重载 ,
//允许用户在自己定义的类里仅定义少量的 操作符(最少两个)，就可以方便的自动生成其他的操作符。
#include <iostream>
#include <utility>

class Foo {
	public:
	int n;
   //1				//虽然类中只重载了==和<两个关系操作符，但使用命名空间rel_ops后便可以得到6个。
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
	//lexical  字面量 词汇	实现 字符串和文字之间的转换
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
	using namespace std::rel_ops;	 //一下操作符，自动重载了，使用这个命名空间

	std::cout << std::boolalpha;		 //设置标志,输出 true flase 
	std::cout << "not equal?     : " << (f1 != f2) << '\n';
	std::cout << "greater?       : " << (f1 > f2) << '\n';
	std::cout << "less equal?    : " << (f1 <= f2) << '\n';
	std::cout << "greater equal? : " << (f1 >= f2) << '\n';
	getchar();

  //数字和字符串的转换	std::stringstream boost::formate  (高级的格式)
	std::cout	<< boost::lexical_cast<std::string> (0x10)	 <<std::endl;
	std::cout	<< boost::lexical_cast<int> ("20097610")	 <<std::endl;
	 std::cout	<< boost::lexical_cast<bool> ("0")	 <<std::endl;// bool 只是 0 1
	 //不能转换会抛出异常

	 try
	 {
		  std::cout	<< boost::lexical_cast<bool> ("2")	 <<std::endl;
	 }
	 catch (boost::bad_lexical_cast &e)
	 {
		 std::cout<<"error:"<<e.what();
	 }

	 getchar();
	 //数组转换 可以用 num_valid()进行判断是否能进行转换
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




