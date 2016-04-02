#ifndef Tree_
#define Tree_
#include "TreeNode.h"
#include <queue>
#include <cstring>
#include <algorithm>

template<class T>
class Tree{
private:
	int maxn;
	TreeNode<T>*root;
	TreeNode<T>* find(TreeNode<T>*r,T p);
	void solve(TreeNode<T>*r);
	
public:
	Tree(T p);
	void addSon(T p,T son);
	void addBro(T p,T bro);
	void show(TreeNode<T>*r);
	TreeNode<T>*getRoot();
	int maxWeith();
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
	if(maxn<t)maxn=t;
	solve(r->son);
	solve(r->bro);
}

template<class T>
int Tree<T>::maxWeith(){
	solve(root);
	return maxn;
	
}

template<class T>
Tree<T>::Tree(T p){
	root=new TreeNode<T>(p);
	maxn=-100;
}

template<class T>
void Tree<T>::addSon(T p,T son){
	TreeNode<T>*np=find(root,p);
	if(np){
		np->son=new TreeNode<T>(son);
	}
	else std::cout<<p<<"  NOT IN THIS TERR !"<<std::endl;
}

template<class T>
void Tree<T>::addBro(T p,T bro){
	TreeNode<T>*np=find(root,p);
	if(np){
		np->bro=new TreeNode<T>(bro);
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