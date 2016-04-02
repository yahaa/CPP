#include <iostream>
using namespace std;
const int maxn=1000000;
int a[maxn];
int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n-1;i++)cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
	
}