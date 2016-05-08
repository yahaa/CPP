#include <iostream>
#include "LBT.h"
using namespace std;
int main(){
	LBT<int>b;
	b.buildRoot(10);
	b.addLeft(10,5);
	b.addRight(10,14);
	b.addLeft(5,2);
	b.addRight(5,6);
	b.addLeft(14,12);
	b.addRight(14, 16);
	b.inOrder(b.getRoot());
	cout<<endl;
	if(b.isBST())cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	b.BMX(b.getRoot(),10);
	cout<<b.location(6)->date<<endl;

}