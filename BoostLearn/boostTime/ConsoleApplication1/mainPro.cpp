#include <boost/timer.hpp>
#include <boost/progress.hpp>

#include <iostream>
#include <stdio.h>
#include <vector>

void FunctionCostTime()
{
	{
		boost::progress_timer _progressTime;
		std::cout<<"FunctionCostTime----";
		// Sleep(1000);
		for (int i=0;i<10000000;++i);
	}
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
int main()
{
	boost::timer _t;
    std::cout <<	_t.elapsed_max()<<std::endl;
    std::cout <<	_t.elapsed_min()<<std::endl;
    std::cout <<	_t.elapsed()<<std::endl;
    _t.restart();
	  std::cout <<	_t.elapsed()<<std::endl;

	  FunctionCostTime();
	

	  std::vector<std::string> _vec(150,"aaa");
	  _vec[20]="";
	  //boost::progress_display _pd(_vec.size());
	   boost::progress_display _pd(_vec.size(),std::cout,"%%%","+++","+++")	 ;
	   std::ofstream fs(("c:\\testProgress.txt"));
	  std::vector<std::string>::iterator _it= _vec.begin();
	  while (_it != _vec.end())
	  {
		fs<<*_it<<"\n";
			   	++_pd;
			if(*_it == "")
			{
				std::cout<<_it-_vec.begin()<<std::endl;

				_pd.restart(_vec.size());	 //重新绘制一个新的进度，否则会乱
				_pd+=(_it-_vec.begin()+1);
			}
			++_it;
		
	  }
	    getchar();
		return 0;
}