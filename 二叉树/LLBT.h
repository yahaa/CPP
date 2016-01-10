#ifndef LLBT_
#define LLBT_
#include"LLBTN.h"
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
template<class T>
class LLBT{
protected:
	LLBTN<T>*root;
public:
	LLBT();
	LLBT(const T p);
	void buildRoot(T p);
	virtual ~LLBT();
	void addLeft(T current,T left);
	void addRight(T current,T right);
	bool isEmpty();
	void preOrder(LLBTN<T>*r);
	void inOrder(LLBTN<T>*r);
	void postOrder(LLBTN<T>*r);
	LLBTN<T>*&getRoot();
	void findNPIn(T p);
	void findNPpre(T p);
	void findNPPost(T p);
	
private:
	LLBTN<T>* find(LLBTN<T>*p,T &e);
	void inOrderT(LLBTN<T>*p,LLBTN<T>*&pre=NULL);
	void preOrderT(LLBTN<T>*p,LLBTN<T>*&pre=NULL);
	void postOrderT(LLBTN<T>*p,LLBTN<T>*&pre=NULL);
	
};
#endif

template<class T>
void LLBT<T>::findNPIn(T p){
	LLBTN<T>*t=NULL;
	inOrderT(root,t);
	LLBTN<T>*temp=find(root,p);
	if(temp->rightt=1)cout<<temp->rightChild->date<<endl;
	else cout<<"can't found !"<<endl;
}
// =================================================
template<class T>
void LLBT<T>::findNPpre(T p){
	LLBTN<T>*t=NULL;
	preOrderT(root,t);
	LLBTN<T>*temp=find(root,p);
	if(temp->rightt=1)cout<<temp->rightChild->date<<endl;
	else cout<<"can't found !"<<endl;
}


template<class T>
void LLBT<T>::findNPPost(T p){
	LLBTN<T>*t=NULL;
	postOrderT(root,t);
	LLBTN<T>*temp=find(root,p);
	if(temp->rightt=1)cout<<temp->rightChild->date<<endl;
	else cout<<"can't found !"<<endl;
}


template<class T>
void LLBT<T>::inOrderT(LLBTN<T>*p,LLBTN<T>*&pre){
	if(p!=NULL){
		inOrderT(p->leftChild,pre);
		if(p->leftChild==NULL){
			p->leftChild=pre;
			p->leftt=1;
		}
		else p->leftt=0;
		if(pre!=NULL&&pre->rightChild==NULL){
			pre->rightChild=p;
			pre->rightt=1;
		}
		else if(pre!=NULL)pre->rightt=0;
		pre=p;
		inOrderT(p->rightChild,pre);

	}
}


template<class T>
void LLBT<T>::preOrderT(LLBTN<T>*p,LLBTN<T>*&pre){
	if(p!=NULL){
		
		if(p->leftChild==NULL){
			p->leftChild=pre;
			p->leftt=1;
		}
		else p->leftt=0;
		if(pre!=NULL&&pre->rightChild==NULL){
			pre->rightChild=p;
			pre->rightt=1;
		}
		else if(pre!=NULL)pre->rightt=0;
		pre=p;
		 if(p->leftt==0)preOrderT(p->leftChild,pre);
	     if(p->rightt==0) preOrderT(p->rightChild,pre);
	}
}

template<class T>
void LLBT<T>::postOrderT(LLBTN<T>*p,LLBTN<T>*&pre){
	if(p!=NULL){
		postOrderT(p->leftChild,pre);
		postOrderT(p->rightChild,pre);
		if(p->leftChild==NULL){
			p->leftChild=pre;
			p->leftt=1;
		}
		else p->leftt=0;
		if(pre!=NULL&&pre->rightChild==NULL){
			pre->rightChild=p;
			pre->rightt=1;
		}
		else if(pre!=NULL)pre->rightt=0;
		pre=p;
	}
}

template<class T>
LLBTN<T>* LLBT<T>::find(LLBTN<T>*p,T &e){
	if(p==NULL||p->date==e)return p;
	else {
		LLBTN<T>*temp=find(p->leftChild,e);
		if(temp!=NULL)return temp;
		else return find(p->rightChild,e);
	}
}

template<class T>
LLBT<T>::LLBT(){
	root=NULL;
}

template<class T>
LLBT<T>::LLBT(const T p){
	root=new LLBTN<T>(p);
}

template<class T>
LLBT<T>::~LLBT(){

}

template<class T>
void LLBT<T>::buildRoot(T p){
	if(root==NULL)root=new LLBTN<T>(p);
}

template<class T>
void LLBT<T>::addRight(T current,T right){
	LLBTN<T>*temp=find(root,current);
	if(temp!=NULL)temp->rightChild=new LLBTN<T>(right);
}


template<class T>
void LLBT<T>::addLeft(T current,T left){
	LLBTN<T>*temp=find(root,current);
	if(temp!=NULL)temp->leftChild=new LLBTN<T>(left);
}

template<class T>
bool LLBT<T>::isEmpty(){
	if(root==NULL)return true;
	else return false;
}


template<class T>
void LLBT<T>::preOrder(LLBTN<T>*r){
	if(r!=NULL){
		cout<<r->date<<" ";
		preOrder(r->leftChild);
		preOrder(r->rightChild);
	}
}


template<class T>
void LLBT<T>::inOrder(LLBTN<T>*r){
	if(r!=NULL){
		inOrder(r->leftChild);
		cout<<r->date<<" ";
		inOrder(r->rightChild);
	}
}


template<class T>
void LLBT<T>::postOrder(LLBTN<T>*r){
	if(r!=NULL){
		postOrder(r->leftChild);
		postOrder(r->rightChild);
		cout<<r->date<<" ";
	}
}

template<class T>
LLBTN<T>*&LLBT<T>::getRoot(){
	return root;
}


