#ifndef CommonFuntion_        //��д���ͷ�ļ���Ҫ��Ϊ�˷���̳�ʱʹ��   ,��Щ�����ں���ĵ�Ԫ�л�Ҫ�õ�   ���� ��������
#define CommonFuntion_          //ͬʱҲΪ��  ��ϰʲô�Ǵ��麯��   ʲô�ǳ�����
#include<iostream>
#include<ostream>
#include<fstream>
#include<string>
using namespace std;
template<class T>
class CommonFuntion{
public:
	virtual ~CommonFuntion(){}
	virtual bool empty()=0;
	virtual  int size()const = 0;
	virtual T&getIndexElem(int index)const = 0;
	virtual int indexOf(const T&theElem)const = 0;
	virtual void erase(int theIndex)= 0;
	virtual void insert(int theIndex,  T theElem) = 0;
	virtual void output(ostream&out)const = 0;
};
#endif
