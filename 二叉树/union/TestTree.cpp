#include <iostream>
#include "Tree.h"
using namespace std;
int main(){
	Tree<char> tree('A');
	char p,adds;
	int select;
	while(cin>>p>>adds>>select)
		tree.addSB(p,adds,select);
	tree.show(tree.getRoot());
	cout<<tree.maxDegree()<<endl;
	return 0;
}

/*
A B 1
B E 1
E F 0
F K 1
K L 0
B C 0
C G 1
C D 0
D H 1
H I 0
I M 1
M N 0
I J 0
*/
