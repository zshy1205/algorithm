#include "mystring.h"

istream &operator>> (istream &is, mystring &mys)
{
	mys.m_date = new char[100];
	is >> mys.m_date;
	return is;
}
ostream &operator<<(ostream & os, const mystring &mys)
{
	os << mys.m_date;
	return os;
}

mystring & mystring::operator=(const char * str)
{
	delete[] m_date;
	//cout << "重载1=" << endl;
	int length = strlen(str);
	m_date = new char[length + 1];
	strcpy_s(m_date, length + 1, str);
	return *this;
}
mystring & mystring::operator=(const mystring &other)
{
	//cout << "重载2=" << endl;
	if (this == &other)
		return *this;
	delete[] m_date;
	int length = strlen(other.m_date);
	m_date = new char[length + 1];
	strcpy_s(m_date,length + 1, other.m_date);
	return *this;//返回本对象的引用
}
mystring::~mystring()
{
	cout << "析构"<<m_date << endl;
	delete[] m_date;
}

mystring::mystring(const mystring &other)
{
	//cout << "复制构造函数" << endl;
	int length = strlen(other.m_date);
	m_date = new char[length + 1];
	strcpy_s(m_date,length + 1, other.m_date);
}

mystring::mystring(const char * str)
{
	//默认构造函数
	//cout << "默认构造" << endl;
	if (str == NULL)
	{
		m_date = new char[1];
		m_date[0] = '\0';
	}
	else
	{
		int length = strlen(str);
		m_date = new char[length + 1];
		strcpy_s(m_date,length + 1, str);
	}
}
mystring::mystring(const char * str, int n)
{
	if (str == NULL)
	{
		m_date = new char[1];
		m_date[0] = '\0';
	}
	else
	{
		int length = strlen(str);
		if (length <= n)//如果目标字符串长度小于截取长度N,则全部复制
		{
			m_date = new char[length + 1];
			strcpy_s(m_date, length + 1, str);
		}
		else
		{
			m_date = new char[n + 1];
			for (int i = 0; i < n; i++)
				m_date[i] = str[i];
			m_date[n] = '\0';
		}
	}
}
mystring::mystring(const mystring &other, int pos)
{
	int length = strlen(other.m_date);
	if (pos >= length)
	{
		m_date = new char[1];
		m_date[0] = '\0';
	}
	else
	{
		m_date = new char[length - pos + 1];
		for (int i = 0; i < length - pos; i++)
			m_date[i] = other.m_date[i + pos];
		m_date[length - pos] = '\0';		
	}
}
mystring::mystring(const mystring &other, int start, int len)
{
	int length = strlen(other.m_date);
	if (start >= length)
	{
		m_date = new char[1];
		m_date[0] = '\0';
	}
	else
	{
		m_date = new char[len + 1];
		int i = -1;
		while (++i < len && other.m_date[i + start] != '\0')
			m_date[i] = other.m_date[i + start];
		m_date[i] = '\0';
	}
}
mystring  mystring::substr(int pos, int n)
{
	mystring res(*this, pos, n);
	return res;
}
mystring  mystring::substr(int pos)
{
	mystring res(*this, pos);
	return res;
}