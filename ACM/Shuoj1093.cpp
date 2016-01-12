#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[4];
	int b[3];
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	b[0]=a[0];
	b[1]=a[1];
	b[2]=a[2];
	sort(b,b+3);
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	while(next_permutation(b,b+3))cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	b[0]=a[0];
	b[1]=a[1];
	b[2]=a[3];
	sort(b,b+3);
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	while(next_permutation(b,b+3))cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	b[0]=a[0];
	b[1]=a[2];
	b[2]=a[3];
	sort(b,b+3);
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	while(next_permutation(b,b+3))cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	b[0]=a[3];
	b[1]=a[1];
	b[2]=a[2];
	sort(b,b+3);
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
	while(next_permutation(b,b+3))cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;

	return 0;
}
