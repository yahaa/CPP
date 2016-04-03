#ifndef Tree_
#define Tree_
#include "TreeNode.h"
#include <queue>
#include <cstring>
#include <algorithm>

template<class T>
class Tree{
private:
	int maxD;
	TreeNode<T>*root;
	TreeNode<T>* find(TreeNode<T>*r,T p);
	void solve(TreeNode<T>*r);
	
public:
	Tree(T p);
	void addSB(T p,T adds,int select);
	void show(TreeNode<T>*r);
	TreeNode<T>*getRoot();
	int maxDegree();
};
#endif

template<class T>
void Tree<T>::solve(TreeNode<T>*r){
	if(r==NULL)return;
	int t=1;
	TreeNode<T>*p=r;
	while(p->bro){
		t++;
		p=p->bro;
	}
	if(maxD<t)maxD=t;
	solve(r->son);
	solve(r->bro);
}

template<class T>
int Tree<T>::maxDegree(){
	solve(root);
	return maxD;
	
}

template<class T>
Tree<T>::Tree(T p){
	root=new TreeNode<T>(p);
	maxD=0;
}

template<class T>
void Tree<T>::addSB(T p,T adds,int select){
	TreeNode<T>*np=find(root,p);
	if(np){
		if(select==1)np->son=new TreeNode<T>(adds);
		else if(select==0)np->bro=new TreeNode<T>(adds);
	}
	else std::cout<<p<<"  NOT IN THIS TERR !"<<std::endl;
}


template<class T>
TreeNode<T>*Tree<T>::getRoot(){
	return root;
}

template<class T>
TreeNode<T>*Tree<T>::find(TreeNode<T>*r,T p){
	if(r==NULL||r->data==p)return r;
	else {
		TreeNode<T>*temp=find(r->son,p);
		if(temp!=NULL)return temp;
		else return find(r->bro,p);
	}
}

template<class T>
void Tree<T>::show(TreeNode<T>*r){
	if(r==NULL)return;
	std::cout<<r->data<<" "<<std::endl;
	show(r->son);
	show(r->bro); 
}