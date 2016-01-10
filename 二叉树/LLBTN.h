#ifndef LLBTN_
#define LLBTN_
#include<iostream>
using namespace std;
template<class T>
class LLBTN{
public:
	T date;
	LLBTN<T>*leftChild;
	LLBTN<T>*rightChild;
	int leftt,rightt;
	LLBTN();
	LLBTN(const T & date,LLBTN<T>* lChild=NULL,LLBTN<T>* rChild=NULL,int leftt=0,int rightt=0);
};
#endif

template<class T>
LLBTN<T>::LLBTN(){
	leftChild=NULL;
	rightChild=NULL;
	leftt=rightt=0;
}

template<class T>
LLBTN<T>::LLBTN(const T&date,LLBTN<T>*lChild,LLBTN<T>*rChild,int leftt,int rightt){
	this->date=date;
	this->leftt=leftt;
	this->rightt=rightt;
	leftChild=lChild;
	rightChild=rChild;

}