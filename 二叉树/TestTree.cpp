#include"ArrayTree.h"
#include<iostream>
using namespace std;
int main(){
	ArrayTree<int>a;
	a.buildRoot(10);
	a.addLeft(10,6);
	a.addRight(10,8);
	a.addRight(6,20);
	a.addLeft(6,12);
	a.addRight(8,1);
	a.addLeft(8,2);
	cout<<a.closetRoot(12,2)<<endl;
	a.levelOrder();
	cout<<endl;
	a.preOrder(a.getRoot());
	cout<<endl;
	a.inOrder(a.getRoot());
	cout<<endl;
	a.postOrder(a.getRoot());
return 0;
}