#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[10];
	for(int i=0;i<10;i++)a[i]=i;
	cout<<lower_bound(a,a+10,-1)-a;
}