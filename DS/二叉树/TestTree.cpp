#include"ArrayTree.h"
#include"LBT.h"
#include"LLBT.h"
#include <iostream>

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
	cout<<"第六章上机第七题"<<endl;
	cout<<a.closetRoot(12,2)<<endl;   //第六章上机第七题
	a.levelOrder();
	cout<<endl;
	a.preOrder(a.getRoot());
	cout<<endl;
	a.inOrder(a.getRoot());
	cout<<endl;
	a.postOrder(a.getRoot());
	cout<<endl;

	LBT<int>b,e;
	b.buildRoot(10);
	b.addLeft(10,5);
	b.addRight(10,6);
	b.addRight(6, 100);
	b.addLeft(5,1);
	//b.addRight(5, 113);
	b.addLeft(1,9);
	b.addRight(1,3);
	b.addLeft(9,20);
	b.addRight(9, 34);
	b.addLeft(6,18);
	//b.addLeft(18,30);
	//b.addRight(18, 111);
	b.preOrder(b.getRoot());
	cout<<endl;
	b.inOrder(b.getRoot());
	cout<<endl;
	b.postOrder(b.getRoot());
	cout<<endl;
	cout<<"第六章上机第9 题"<<endl;
	cout<<b.getBreadth();  //第六章上机第9 题
	cout<<endl;
	cout<<"第六单元 14 题"<<endl;
	cout<<b.numberNode(b.getRoot())<<endl;   //第六单元 14 题

	e.buildRoot(10);
	e.addLeft(10,5);
	e.addRight(10,6);
	//b.addRight(6, 100);
	e.addLeft(5,1);
	//b.addRight(5, 113);
	e.addLeft(1,9);
	e.addRight(1,3);
	e.addLeft(9,20);
	e.addRight(9, 34);
	e.addLeft(6,18);
	cout<<"测试两棵树是否相似"<<endl;
	cout<<similar(b.getRoot(),e.getRoot())<<endl;

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
	cout<<endl;
	cout<<"第六单元 上机第十二  题"<<endl;
	//c.findNPpre(10);//测试  // 第六单元 上机第十二  题
	c.findNPPost(30);   //测试  // 第六单元 上机第十三  题     注意两题不能同时测试

return 0;
}