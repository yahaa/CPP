#ifndef LBTN_
#define LBTN_
#include<iostream>
using namespace std;
template<class T>
class LbinTreeNode{
public:
	T date;
	LbinTreeNode<T>*leftChild;
	LbinTreeNode<T>*rightChild;
	
	LbinTreeNode();
	LbinTreeNode(const T & date,LbinTreeNode<T>* lChild=NULL,LbinTreeNode<T>* rChild=NULL);
};
#endif

template<class T>
LbinTreeNode<T>::LbinTreeNode(){
	leftChild=NULL;
	rightChild=NULL;
}

template<class T>
LbinTreeNode<T>::LbinTreeNode(const T&date,LbinTreeNode<T>*lChild,LbinTreeNode<T>*rChild){
	this->date=date;
	leftChild=lChild;
	rightChild=rChild;
}