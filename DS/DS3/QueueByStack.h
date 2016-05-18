#ifndef Queue_            //上机第5题
#define Queue_
#include"Stack.h"
template<class T>
class Queue{
protected:
	Stack<T>s1, s2;       //用自定义的栈
public:               
	     //在此题情况下无需     定义构造函数       系统调用默认构造函数
	void push(T  e);
	bool empty();
	 T out();
};

#endif 
template<class T>
bool Queue<T>::empty(){
	return s1.empty() && s2.empty();            //当  s1   s2   全部为空时   队列为空  
}
template<class T>
void Queue<T>::push(T e){
	s1.push(e);           //s1用于  队列的插入   
}

template<class T>
T Queue<T>::out(){
	if (s2.empty())       //如果s2 为空        把s1  中的元素倒到   s2  中
	while (!s1.empty())s2.push(s1.pop());       //   s1  中的元素全部搬家
	return s2.pop();         //s2  用于队列的输出
}