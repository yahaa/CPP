#ifndef LBT_
#define LBT_
#include"LBTN.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
template<class T>
class LBT{
protected:
	LbinTreeNode<T>*root;
	int a[100];
public:
	LBT();
	LBT(const T p);
	void buildRoot(T p);
	virtual ~LBT();
	void addLeft(T current,T left);
	void addRight(T current,T right);
	bool isEmpty();
	void preOrder(LbinTreeNode<T>*r);
	void inOrder(LbinTreeNode<T>*r);
	void postOrder(LbinTreeNode<T>*r);
	void levelOrder();
	LbinTreeNode<T>*&getRoot();
	//T getParent(T e);
	LbinTreeNode<T>*findParent(LbinTreeNode<T>*r, T p);
	T getLeft(T p);
	T getRitht(T p);
	void setElem(T p,T e);
	void deleteLeft(T p);
	void deleteRight(T p);
	//第六章上机第9 题
	void breadth(LbinTreeNode<T>*t,int i); 
	int getBreadth();  
	friend bool similar(LbinTreeNode<T>*a,LbinTreeNode<T>*b);

	int numberNode(LbinTreeNode<T>*r);
private:
	LbinTreeNode<T>* find(LbinTreeNode<T>*p,T &e);
	
	
};
#endif

template <class T>
bool similar(LbinTreeNode<T>*a,LbinTreeNode<T>*b){
	if(a==NULL||b==NULL)return (a==NULL&&b==NULL);
	return similar(a->leftChild,b->leftChild)&&similar(a->rightChild,b->rightChild);
}


template<class T>      //第六章上机第9 题
void LBT<T>::breadth(LbinTreeNode<T>*t,int i){
	if(t!=NULL){
		if(i==0)a[0]=1;
		if(t->leftChild!=NULL)a[i+1]++;
		if(t->rightChild!=NULL)a[i+1]++;
		breadth(t->leftChild,i+1);
		breadth(t->rightChild,i+1);
	}
	
}
template<class T> 
int LBT<T>::getBreadth(){
	breadth(root,0);
	int maxn=0;
	for(int i=0;i<10;i++){
		cout<<a[i]<<endl;
		maxn=max(maxn,a[i]);
	}
	return maxn;
}


template<class T>
int LBT<T>::numberNode(LbinTreeNode<T>*r){    //第六单元 14 题
	if(r==NULL)return 0;
	if(r->leftChild==NULL && r->rightChild==NULL) return 1;
	if(r->leftChild!=NULL || r->rightChild!=NULL) return numberNode(r->leftChild)+numberNode(r->rightChild); 
}


template<class T>
LbinTreeNode<T>*LBT<T>::findParent(LbinTreeNode<T>*r, T p){
	if(r==NULL||r->date==p)return NULL;
	else if((r->leftChild)->date==p||(r->rightChild)->date==p)return r;
	else{
		LbinTreeNode<T>*temp;
		temp=findParent(r->leftChild,p);
		if(temp!=NULL)return temp;
		temp=findParent(r->rightChild,p);
		if(temp!=NULL)return temp;
		return NULL;
	}
	
}



template<class T>
LbinTreeNode<T>* LBT<T>::find(LbinTreeNode<T>*p,T &e){
	if(p==NULL||p->date==e)return p;
	else {
		LbinTreeNode<T>*temp=find(p->leftChild,e);
		if(temp!=NULL)return temp;
		else return find(p->rightChild,e);
	}
}

template<class T>
LBT<T>::LBT(){
	root=NULL;
	memset(a,0,sizeof(a));
}

template<class T>
LBT<T>::LBT(const T p){
	root=new LbinTreeNode<T>(p);
}

template<class T>
LBT<T>::~LBT(){

}

template<class T>
void LBT<T>::buildRoot(T p){
	if(root==NULL)root=new LbinTreeNode<T>(p);
}

template<class T>
void LBT<T>::addRight(T current,T right){
	LbinTreeNode<T>*temp=find(root,current);
	if(temp!=NULL)temp->rightChild=new LbinTreeNode<T>(right);
}


template<class T>
void LBT<T>::addLeft(T current,T left){
	LbinTreeNode<T>*temp=find(root,current);
	if(temp!=NULL)temp->leftChild=new LbinTreeNode<T>(left);
}

template<class T>
bool LBT<T>::isEmpty(){
	if(root==NULL)return true;
	else return false;
}


template<class T>
void LBT<T>::preOrder(LbinTreeNode<T>*r){
	if(r!=NULL){
		cout<<r->date<<" ";
		preOrder(r->leftChild);
		preOrder(r->rightChild);
	}
}


template<class T>
void LBT<T>::inOrder(LbinTreeNode<T>*r){
	if(r!=NULL){
		inOrder(r->leftChild);
		cout<<r->date<<" ";
		inOrder(r->rightChild);
	}
}


template<class T>
void LBT<T>::postOrder(LbinTreeNode<T>*r){
	if(r!=NULL){
		postOrder(r->leftChild);
		postOrder(r->rightChild);
		cout<<r->date<<" ";
	}
}


template<class T>
LbinTreeNode<T>*&LBT<T>::getRoot(){
	return root;
}


template<class T>
T LBT<T>::getLeft(T p){
	LbinTreeNode<T>*temp=find(root,p);
	if(temp==NULL){
		cout<<p<<" not in this tree"<<endl;
		exit(0);
	}
	return temp->leftChild->date;
}

template<class T>
T LBT<T>::getRitht(T p){
	LbinTreeNode<T>*temp=find(root,p);
	if(temp==NULL){
		cout<<p<<" not in this tree"<<endl;
		exit(0);
	}
	return temp->rightChild->date;
}


template<class T>
void LBT<T>::setElem(T p,T e){
	LbinTreeNode<T>*temp=find(root,p);
	if(temp==NULL){
		cout<<p<<" not in this tree"<<endl;
		exit(0);
	}

	temp->date=e;
}

template<class T>
void LBT<T>::deleteRight(T p){
	LbinTreeNode<T>*temp=find(root,p);
	if(temp==NULL){
		cout<<p<<" not in this tree"<<endl;
		exit(0);
	}
	temp->rightChild=NULL;
}


template<class T>
void LBT<T>::deleteLeft(T p){
	LbinTreeNode<T>*temp=find(root,p);
	if(temp==NULL){
		cout<<p<<" not in this tree"<<endl;
		exit(0);
	}
	temp->leftChild=NULL;
}