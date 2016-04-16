#ifndef LinkList_        //������ͷ�ļ�
#define LinkList_
#include"CommonFuntion.h"
#include "Node.h"
#include<iostream>
using namespace std;
template<class T>
class linkList :public CommonFuntion<T>{
protected:
	Node<T>*firstNode;
	int sizes;
public:
	//���캯���Լ����������Լ�����
	linkList();
	linkList(const linkList<T>&);
	virtual ~linkList();
	//���廯������   
	virtual bool empty();//,,,,,,,
	virtual  int size()const;
	virtual T&getIndexElem(int index)const;     
	virtual int indexOf(const T&theElem)const;
	virtual void erase(int theIndex);    //ɾ��ָ��λ�õ�Ԫ��
	virtual void insert(int theIndex, T theElem);       //ָ��λ�ò���    theElem
	virtual void output(ostream&out)const;
	//�¼ӷ���
	virtual void push_back(T e);        //β�����     ���������  ������½��о����õ�   
	virtual void push_order(T e);       //����ʱ����     
	virtual void exchang(int i, int j);       //��������λ�õ�Ԫ��
	virtual void reserse();        //��������    
	virtual void sort();
	//virtual Node<T>& operator  [](int i);       //�����ûд��   mgw   �������������   
	 
	linkList<T> &operator +(const  linkList<T>&tm);    //����     +
	linkList<T>&operator =(const linkList<T>&tm);    // ����  = 
 
};

#endif
//������ʵ�ֹ���     ����Ĳ�ע����
template <class T>
linkList<T>&linkList<T>::operator +(const  linkList<T>&tm){
	linkList<T> temp(*this);
	Node<T>*p = tm.firstNode;
	T e;
	for (int i = 0; i < tm.size(); i++){
		e = p->elem;
		temp.push_order(e);
		p = p->next;
	}
	temp.reserse();
	*this = temp;
	return *this;
}




template <class T>
linkList<T>&linkList<T>::operator=(const linkList<T>&tm){
	if (this == &tm)return *this;
	while (firstNode){
		Node<T>*nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
	sizes = 0;
	//Node<T>*p = firstNode;
	Node<T>*p1= tm.firstNode;
	T e;
	for (int i = 0; i < tm.size(); i++){
		e = p1->elem;
		if (sizes == 0){
			firstNode = new Node<T>(e, firstNode);
		}
		else {
			Node<T>*p = firstNode;
			for (int i = 0; i <sizes - 1; i++)p = p->next;
			p->next = new Node<T>(e, p->next);
			//p->next->next = NULL;
		}
		sizes++;
		p1 = p1->next;
	}

	return *this;
}


template<class T>
void linkList<T>::push_order(T e){    //���Ӷ�  �ϸ�    ������  ------

	if (sizes == 0){
		firstNode = new Node<T>(e, firstNode);
	}
	else {
		Node<T>*p = firstNode;
		if (sizes==1){
			if ((firstNode->elem)<e)p->next = new Node<T>(e, p->next);
			else {
				p = new Node<T>(e, firstNode);
				firstNode = p;
			}
		}
		else {
			if (firstNode->elem > e){
				p = new Node<T>(e, firstNode);
				firstNode = p;
			}
			else{
				for (int i = 0; i < sizes - 1 && p->next->elem <e; i++)p = p->next;
				p->next = new Node<T>(e, p->next);
			}
		}
	}
	sizes++;
}


template<class T>
void linkList<T>::insert(int theIndex, T  theElem){
	if (theIndex<0 || theIndex>sizes){
		cout << "the index error" << endl;
		return;
	}
	else {
		if (sizes == 0){
			firstNode = new Node<T>(theElem, firstNode);
		}
		else {
			Node<T>*p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)p = p->next;
			p->next = new Node<T>(theElem, p->next);
		}
		sizes++;
	}
}


template<class T>
void linkList<T>::push_back(T e){
	//Node<T>*p = firstNode;
	if (sizes == 0){
		firstNode = new Node<T>(e, firstNode);
	}
	else {
		Node<T>*p = firstNode;
		for (int i = 0; i <sizes - 1; i++)p = p->next;
		p->next = new Node<T>(e, p->next);
		//p->next->next = NULL;
	}
	sizes++;
}

/*template <class T>
linkList<T> & linkList<T>::operator +(const linkList<T>&tm){
	Node<T>*p = firstNode;
	while (p->next)p = p->next;
	p->next = tm.firstNode;
	return *this;
}*/

/*template<class T>
Node<T>& linkList<T>::operator [](int i){

	if (sizes == 0){
		cout << "list is empty" << endl;
	}
	else if (i<0 || i>sizes){
		cout << "the index error" << endl;
	}
	else {
		Node<T> *p = firstNode;
		for (int j = 0; j<i; j++)p = p->next;
		return *p;
	}
}*/
template <class T>
void linkList<T>::sort(){
	for (int i = 0; i<sizes - 1; i++){
		for (int j = i + 1; j<sizes; j++){

		}
	}
}
template <class T>
void linkList<T>::exchang(int i, int j){                       //��������λ�õ�Ԫ�ػ�λ
	if (i <0 || i > sizes)cout << "error index" << endl;
	else{
		T temp;
		Node<T>*p1 = firstNode;
		for (int k = 0; k < i; k++)p1 = p1->next;
		temp = p1->elem;
		Node<T>*p2 = firstNode;
		for (int k = 0; k < j; k++)p2 = p2->next;
		p1->elem = p2->elem;
		p2->elem = temp;

	}

}
template<class T>
void linkList<T>::reserse(){                 //ʵ��Ԫ������      �ռ临�ƶ�  Ϊ   O��1��   
	for (int i = 0, j = sizes - 1; i < j; i++, j--)exchang(i, j);
}

template <class T>
void linkList<T>::output(ostream&out)const{
	Node<T>*p = firstNode;
	while (p != NULL){
		out << p->elem << " ";
		p = p->next;
	}
}


template<class T>
void linkList<T>::erase(int theIndex) {
	if (theIndex<0 || theIndex>sizes){
		cout << "the index error" << endl;
		return;
	}
	else {
		Node<T>*deleteNode;
		if (theIndex == 0){
			deleteNode = firstNode;
			firstNode = firstNode->next;
		}
		else {
			Node<T>*p = firstNode;
			for (int i = 0; i < theIndex - 1; i++)p = p->next;
			deleteNode = p->next;
			p->next = deleteNode->next;
		}
		sizes--;
		delete deleteNode;
	}
}
template<class T>
int linkList<T>::indexOf(const T&theElem)const{
	Node<T>*nextp = firstNode;
	int i = 0;
	while (nextp->elem != theElem&&nextp != NULL){
		nextp = nextp->next;
		i++;
	}
	if (nextp == NULL)return -1;
	else return i;
}


template<class T>
T& linkList<T>::getIndexElem(int index)const{
	if (index<0 || index>sizes){
		cout << "index error" << endl;
		exit(0);
	}

	
		Node<T>*next = firstNode;
		for (int i = 0; i < index; i++)next = next->next;
		return next->elem;

}

template<class T>
int linkList<T>::size()const{
	return sizes;
}


template<class T>
bool linkList<T>::empty(){
	return sizes == 0;
}


template<class T>
linkList<T>::~linkList(){
	while (firstNode){
		Node<T>*nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}


template <class T>
linkList<T>::linkList(const linkList<T>&list){
	sizes = list.sizes;
	if (sizes == 0){
		firstNode = NULL;
		return;
	}

	Node<T>*temp = list.firstNode;     //tempָ��list�� ͷָ��
	firstNode = new Node<T>(temp->elem);
	temp = temp->next;
	Node<T>*opNode = firstNode;       //opNode ��firstNodeָ��ͬһ���ڴ�
	while (temp != NULL){
		opNode->next = new Node<T>(temp->elem);
		opNode = opNode->next;
		temp = temp->next;
	}
	opNode->next = NULL;
}


template <class T>
linkList<T>::linkList(){
	firstNode = NULL;         //��ͷ�ڵ�
	sizes = 0;
}
