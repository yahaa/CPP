#ifndef Node_      //节点头文件     这里是我的编写的风格问题   和老师课本上的都不一样   但是原理基本上相同
#define Node_
#include<iostream>
#include<ostream>
#include<fstream>
using namespace std;
template<class T>
class Node{      //课本上用的是   结构    struct    原理一样的
public:
	T elem;
	Node<T>*next;
	Node(){}; 
	Node(const T&elem){      //   构造  next = NULL的构造函数    
		this->elem = elem;
		next = NULL;
	}       //用于 链表拷贝时
	Node(const T&elem, Node<T>*nextp){      //方便   链表中的   inseart  操作   这样做使得  编写linkList  头问价更加简洁
		this->elem = elem;               //在还没有理解好课本的情况下建议 先搞懂课本的那种原理   我的这种   是建立在那种原理的基础上的
		this->next = nextp;
	}
	virtual void output(ostream&out){
		out << elem;
	}
	//friend ostream & operator  <<(ostream&out,Node<T>&e);

};
#endif
