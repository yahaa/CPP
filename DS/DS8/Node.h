#ifndef Node_
#define Node_
class Node{
	int data;
	int count;
	Node* lchild;
	Node* rchild;
	Node();
	Node(int data);
};
#endif
Node::Node(){
	lchild=NULL;
	rchild=NULL;
	count=0;
	data=-1000;
}

Node::Node(int data){
	lchild=NULL;
	rchild=NULL;
	count=0;
	this->data=data;
}