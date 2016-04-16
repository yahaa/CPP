#ifndef Stack_
#define Stack_
#include<iostream>
using namespace std;
template <class T>
class Stack{
protected:
	int top;
	int maxsize;
	T*elem;
public:
	Stack(int maxsize = 20);
	virtual ~Stack(){ delete[]elem; }
	bool empty();
	T Top();
	T pop();
	void push(T e);
	void expandTheMaxSize();        //扩展   空间
};
#endif


template<class T>
void Stack<T>::expandTheMaxSize(){
	if (top == maxsize){       //maxs=-1  情况下默认扩展两倍的空间
			T *telem = new  T[maxsize * 2];
			copy(elem, elem + top, telem);
			delete[]elem;
			elem = telem;
	}
}


template< class T>
Stack<T>::Stack(int maxsize){
	this->maxsize = maxsize;
	top = -1;
	elem = new T[maxsize];
}


template<class T>
bool Stack<T>::empty(){
	return top<0;
}


template<class T>
T Stack<T>::Top(){
	if (top < 0){
		cout << "the Stack is empty" << endl;
		exit(0);
	}
	return elem[top - 1];
}


template<class T>
T Stack<T>::pop(){
	if (!empty())return elem[top--];
	else cout << "Stack is empty" << endl;
}


template<class T>
void Stack<T>::push(T e){
	if (top<maxsize)elem[++top] = e;
	else cout << "Stack is full" << endl;
}
