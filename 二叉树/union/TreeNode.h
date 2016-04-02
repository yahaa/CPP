#ifndef TreeNode_
#define TreeNode_
template<class T>
class TreeNode{
public:
	T data;
	TreeNode<T>*son;
	TreeNode<T>*bro;
	TreeNode(T data);
};
#endif

template<class T>
TreeNode<T>::TreeNode(T data){
	this->data=data;
	son=NULL;
	bro=NULL;
}