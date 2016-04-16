#include <iostream>
#include "Heap.h"
using namespace std;
int main(){
	int a[10];
	for(int i=0;i<10;i++)a[i]=i+1;
	Heap<int>b(a,10);
	cout<<b.isHeap();
	cout<<endl;
}