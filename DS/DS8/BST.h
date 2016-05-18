<<<<<<< HEAD
#include "Node.h"
#ifndef BST_
#define BST_
class BST{
protected:
	Node *root;
public:
	BST(int t);
	void add(Node*r,int t);
private:
	void build(int t);
	
};
#endif
BST::BST(int t){
	root=new Node(t);
}

void BST::build(int t){
	add(root,t);
}

void BST::add(Node*r,int t){
	if(r){
		if(r->data>t){
			if
		}
	}
=======
#ifndef BST_
#define BST_
#include "BSTN.h"
template <class T>
class BST{
private:
	int counts;
	BSTN<T>*root;
	BSTN<T>* innerf(T &key,BSTN<T>*&f);
	void out(BSTN<T>*r);
public:
	BST();
	bool isEmpty();
	void insert(T e);
	void find(T e);
	void print();

};
#endif

template<class T>
void BST<T>::out(BSTN<T>*r){
	if(r==NULL)return;
	out(r->lchild);
	std::cout<<"[ "<<r->data<<","<<r->count<<" ]"<<std::endl;
	out(r->rchild);
}

template<class T>
void BST<T>::print(){
	out(root);
}
template<class T>
BST<T>::BST(){
	root=NULL;
	counts=0;
}

template<class T>
void BST<T>::find(T e){
	BSTN<T>*f=NULL;
	BSTN<T>*ans=innerf(e,f);
	if(ans)ans->count++;
	else insert(e);
}

template<class T>
void BST<T>::insert(T e){
	BSTN<T> *f=NULL;
	BSTN<T> *ans=innerf(e,f);
	if(ans==NULL){
		BSTN<T>*p;
		p=new BSTN<T>(e);
		if(isEmpty())root=p;
		else if(e<f->data)f->lchild=p;
		else f->rchild=p;
		counts++;
	}
}

template<class T>
BSTN<T>* BST<T>::innerf(T &key,BSTN<T> *&f){
	BSTN<T>*p=root;
	while(p!=NULL&&p->data!=key){
		if(key<p->data){
			f=p;
			p=p->lchild;
		}
		else {
			f=p;
			p=p->rchild;
		}
	}
	return p;
}

template<class T>
bool BST<T>::isEmpty(){
	return counts==0;
>>>>>>> da5a85e1e748cdef91e069278d50c4418ea325a3
}