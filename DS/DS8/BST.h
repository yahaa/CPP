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
}