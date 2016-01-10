#include"ArrayTree.h"
#include"LBT.h"
#include"LLBT.h"
#include<iostream>
using namespace std;

const int mx=100;     //假设有100层
int a[mx];
int i=0;
template<class T>      //第六章上机第9 题
int breadth(LbinTreeNode<T>*t){
	int maxn=0;
	if(t!=NULL){
	if(i==0){   //第一层特殊处理
		a[0]=1;
		i++;
		if(t->leftChild!=NULL) a[i]++;
		if(t->rightChild!=NULL) a[i]++;
	}
	else{
		i++;
		if(t->leftChild!=NULL) a[i]++;
		if(t->rightChild!=NULL) a[i]++;
	}
	maxn=max(maxn,a[i]);
	breadth(t->leftChild);
	i--;   //退回上层 以便于求右边的情况
	breadth(t->rightChild);
	}
return maxn;
}
int main(){
	ArrayTree<int>a;
	a.buildRoot(10);
	a.addLeft(10,6);
	a.addRight(10,8);
	a.addRight(6,20);
	a.addLeft(6,12);
	a.addRight(8,1);
	a.addLeft(8,2);
	cout<<a.closetRoot(12,2)<<endl;   //第六章上机第七题
	a.levelOrder();
	cout<<endl;
	a.preOrder(a.getRoot());
	cout<<endl;
	a.inOrder(a.getRoot());
	cout<<endl;
	a.postOrder(a.getRoot());
	cout<<endl;

	LBT<int>b;
	b.buildRoot(10);
	b.addLeft(10,5);
	b.addRight(10,6);
	b.addLeft(5,1);
	b.addLeft(1,9);
	b.addRight(1,3);
	b.addLeft(9,20);
	b.addLeft(6,18);
	b.addLeft(18,30);
	b.preOrder(b.getRoot());
	cout<<endl;
	b.inOrder(b.getRoot());
	cout<<endl;
	b.postOrder(b.getRoot());
	cout<<endl;
	cout<<breadth(b.getRoot());   //第六章上机第9 题
	cout<<endl;
	cout<<b.numberNode(b.getRoot())<<endl;   //第六单元 14 题


	LLBT<int>c;
	c.buildRoot(10);
	c.addLeft(10,5);
	c.addRight(10,6);
	c.addLeft(5,1);
	c.addLeft(1,9);
	c.addRight(1,3);
	c.addLeft(9,20);
	c.addLeft(6,18);
	c.addLeft(18,30);
	c.preOrder(c.getRoot());
	cout<<endl;
	c.inOrder(c.getRoot());
	cout<<endl;
	c.postOrder(c.getRoot());
	cout<<endl;
	c.preOrder(c.getRoot());
	
	c.findNPpre(20);
	//c.findNPPost(20);
	cout<<endl;

return 0;
}