#ifndef Node_      //�ڵ�ͷ�ļ�     �������ҵı�д�ķ������   ����ʦ�α��ϵĶ���һ��   ����ԭ���������ͬ
#define Node_
#include<iostream>
#include<ostream>
#include<fstream>
using namespace std;
template<class T>
class Node{      //�α����õ���   �ṹ    struct    ԭ��һ����
public:
	T elem;
	Node<T>*next;
	Node(){}; 
	Node(const T&elem){      //   ����  next = NULL�Ĺ��캯��    
		this->elem = elem;
		next = NULL;
	}       //���� ������ʱ
	Node(const T&elem, Node<T>*nextp){      //����   �����е�   inseart  ����   ������ʹ��  ��дlinkList  ͷ�ʼ۸��Ӽ��
		this->elem = elem;               //�ڻ�û�����ÿα�������½��� �ȸ㶮�α�������ԭ��   �ҵ�����   �ǽ���������ԭ��Ļ����ϵ�
		this->next = nextp;
	}
	virtual void output(ostream&out){
		out << elem;
	}
	//friend ostream & operator  <<(ostream&out,Node<T>&e);

};
#endif
