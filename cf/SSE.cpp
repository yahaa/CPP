#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int m,n;
	int a[1001];
	int falg;
	while(cin>>m>>n){
		memset(a,0,sizeof(a));
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j%i==0){
					int t;
					if(a[j]==0)t=1;
					else t=0;
					a[j]=t;
				}
			}
		}
	int ans=0;
		for(int i=1;i<=m;i++)if(a[i]==0)ans++;
			cout<<ans<<endl;
	}
}