#ifndef _HuffmanTreeNode
#define _HuffmanTreeNode
template<class T>
struct HuffamanTreeNode{
	T weight;
	int parent,leftChild,rightChild;
	HuffamanTreeNode();
	HuffamanTreeNode(T w,int p=-1,int lChild=-1,int rChild=-1);
};
#endif

template<class T>
HuffamanTreeNode<T>::HuffamanTreeNode(){
	parent=leftChild=rightChild=-1;
}

template<class T>
HuffamanTreeNode<T>::HuffamanTreeNode(T w,int p,int leftChild,int rChild){
	weight=w;
	parent=p;
	leftChild=lChild;
	rightChild=rChild;
}