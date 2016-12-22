#ifndef __PUBFUNC_H_INCLUDED
#define __PUBFUNC_H_INCLUDED

#include "global.h"

namespace pubfunc
{
	//释放一个指针
	template <typename TPTR>
		inline static void release(TPTR*& _ptr)
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = NULL;
			}
		}

	//释放数组
	template <typename TARRTYPE>
		inline static void releasearray(TARRTYPE*& _ptrarr)
		{
			if (_ptrarr)
			{
				delete[] _ptrarr;
				_ptrarr = NULL;
			}
		}
	//初始化数据
	template <typename TTYPE>
		inline static void identity(TTYPE*& _ptr)
		{
			_ptr = NULL;
		}

	//移除空单元
	//需要手动删除
	template <typename TTYPE>
		inline static TTYPE* skipEmpty(const TTYPE* _ptr, const int size)
		{
			TTYPE* parray = new TTYPE[size];
			memset(parray, 0, sizeof(TTYPE) * size);

			int i = 0, j = 0;
			for (i=0; i<size; i++)
			{
				if (_ptr[i] != NULL)
					parray[j++] = _ptr[i];
			}

			return parray;
		}

	//合并字符串容器为一个字符串
	template <typename TSTR, typename TSTRCON>
		inline static TSTR combine(const TSTRCON& obj, const TSTR& spliter)
		{
			typedef TSTRCON::const_iterator TCIter;
			
			TSTR re;

			TCIter iterdata = obj.begin();
			while (iterdata != obj.end())
			{
				re += *iterdata + spliter;
				++iterdata;
			}

			return re;
		}
}

#endif