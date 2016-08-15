#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long a[16];
void factorial(int n){
	a[0]=0;
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i]=i*a[i-1];
	}
}
int main(){
	factorial(15);
	int t;
	cin>>t;
	while(t--){
		int m;
		cin>>m;
		int ans=0;
		for(int i=15;i>=1;i--){
			int c=0;
			while(a[i]<=m&&m!=0){
				c++;
				m-=a[i];
			}
			ans+=c;
		}
		cout<<ans<<endl;
	}
	return 0;
}
