#ifndef Stack2_               //第四单元上机第四题  
#define Stack2_
#include<iostream>       
using namespace std;           
template <class T>
class Stack2{
protected:
	int top1, top2;       
	int maxsize;
	T*elem;
public:
	Stack2(int maxsize = 20);       //默认情况下  20 
	virtual ~Stack2(){ delete[]elem; }
	bool empty();
	T Top(int select = 1);      //默认情况下  选择  1
	T pop(int select = 1);     //默认情况下  选择  1
	void push(T e, int select = 1);     //默认情况下  选择  1
	//void expand();
};
#endif



template< class T>
Stack2<T>::Stack2(int maxsize){
	this->maxsize = maxsize;     
	top1 = -1;      
	top2 = maxsize;   
	elem = new T[maxsize];
}


template<class T>
bool Stack2<T>::empty(){
	return top1 < 0 && top2 == maxsize;     
}


template<class T>
T Stack2<T>::Top(int select){
	if (select == 1){
		if (top < 0){
			cout << "the Stack is empty" << endl;
			exit(0);
		}
		return elem[top];
	}
	else if (select == 2){
		if (top2 == maxsize){
			cout << "the Stack 2 is empty" << endl;
			exit(0);
		}
		return elem[top2];
	}
	else cout << "select error" << endl;

}


template<class T>
T Stack2<T>::pop(int select){
	if (select == 1){
		if (top1 >= 0)return[top1--];
	}
	else if (select == 2){
		if (top2 < maxsize)return[top2++];
	}
	else cout << "select  error" << endl;
}


template<class T>
void Stack2<T>::push(T e, int select){
	if (top1 != top2 - 1){
		if (select == 1)elem[++top1] = e;
		else if (select == 2)elem[--top2] = e;
		else cout << "select is error" << endl;
	}
	else cout << "the Stack is full" << endl;
}