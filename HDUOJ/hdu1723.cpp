#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n,m;
	long long a[35];
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		memset(a,0,sizeof(a));

		a[0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=m&&i+j<n;j++){
				a[i+j]+=a[i];
			}
		}
		cout<<a[n-1]<<endl;
	}
	return 0;
}