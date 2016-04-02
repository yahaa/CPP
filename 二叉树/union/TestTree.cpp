#include <iostream>
#include "Tree.h"
using namespace std;
int main(){
	Tree<char> tree('A');
	tree.addSon('A','B');
	tree.addSon('B','E');
	tree.addBro('E','F');
	tree.addSon('F','K');
	tree.addBro('K','L');
	tree.addBro('B','C');
	tree.addSon('C','G');
	tree.addBro('C','D');
	tree.addSon('D','H');
	tree.addBro('H','I');
	tree.addSon('I','M');
	tree.addBro('M','N');
	tree.addBro('I','J');

	tree.show(tree.getRoot());
	cout<<tree.maxWeith()<<endl;
}
