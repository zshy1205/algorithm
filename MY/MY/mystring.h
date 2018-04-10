#pragma once
#include "head.h"

class mystring 
{
private:
	char * m_date = NULL;
public:
	mystring(const char * str = NULL);//��ͨ���캯��
	mystring(const mystring &other);//���ƹ��캯��
	mystring(const char * str, int n);//�����ַ���str��ǰn���ַ���s��
	mystring(const mystring &other, int pos);//��Ŀ���ַ����ĵ�pos��ʼ����
	mystring(const mystring &other, int start, int len);//��startλ�ÿ�ʼcopy len��������

	mystring substr(int pos, int n);//�����ַ���λ��Ϊpos�����n���ַ���ɵĴ�
	mystring substr(int pos);//�õ�һ��pos����β�Ĵ�
	mystring & operator=(const mystring &other);//���������=
	mystring & operator=(const char *str);
	~mystring(void);//��������
	friend ostream &operator<< (ostream &os, const mystring &mystring);//����Ϊ��Ԫ����
	friend istream &operator>> (istream &is, mystring &mystring);
	

};