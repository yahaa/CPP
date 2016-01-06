#ifndef CommonFuntion_        //编写这个头文件主要是为了方便继承时使用   ,这些函数在后面的单元中还要用到   所以 ，，，，
#define CommonFuntion_          //同时也为了  复习什么是纯虚函数   什么是抽象类
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
