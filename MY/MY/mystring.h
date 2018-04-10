#pragma once
#include "head.h"

class mystring 
{
private:
	char * m_date = NULL;
public:
	mystring(const char * str = NULL);//普通构造函数
	mystring(const mystring &other);//复制构造函数
	mystring(const char * str, int n);//复制字符串str的前n个字符到s中
	mystring(const mystring &other, int pos);//从目标字符串的第pos开始复制
	mystring(const mystring &other, int start, int len);//从start位置开始copy len长度数据

	mystring substr(int pos, int n);//返回字符串位置为pos后面的n个字符组成的串
	mystring substr(int pos);//得到一个pos到结尾的串
	mystring & operator=(const mystring &other);//重载运算符=
	mystring & operator=(const char *str);
	~mystring(void);//析构函数
	friend ostream &operator<< (ostream &os, const mystring &mystring);//声明为友元函数
	friend istream &operator>> (istream &is, mystring &mystring);
	

};