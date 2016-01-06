#ifndef Queue_            //�ϻ���5��
#define Queue_
#include"Stack.h"
template<class T>
class Queue{
protected:
	Stack<T>s1, s2;       //���Զ����ջ
public:               
	     //�ڴ������������     ���幹�캯��       ϵͳ����Ĭ�Ϲ��캯��
	void push(T  e);
	bool empty();
	 T out();
};

#endif 
template<class T>
bool Queue<T>::empty(){
	return s1.empty() && s2.empty();            //��  s1   s2   ȫ��Ϊ��ʱ   ����Ϊ��  
}
template<class T>
void Queue<T>::push(T e){
	s1.push(e);           //s1����  ���еĲ���   
}

template<class T>
T Queue<T>::out(){
	if (s2.empty())       //���s2 Ϊ��        ��s1  �е�Ԫ�ص���   s2  ��
	while (!s1.empty())s2.push(s1.pop());       //   s1  �е�Ԫ��ȫ�����
	return s2.pop();         //s2  ���ڶ��е����
}