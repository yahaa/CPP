#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int m[367],f[367];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(m,0,sizeof(m));
		memset(f,0,sizeof(f));
		char ch;
		int s,e;
		for(int j=1;j<=n;j++){
			cin>>ch>>s>>e;
			if(ch=='M'){
				for(int i=s;i<=e;i++)m[i]+=1;
			}
			if(ch=='F'){
				for(int i=s;i<=e;i++)f[i]+=1;
			}
		}
		int ans=0;
		for(int i=1;i<=366;i++){
			ans=max(ans,min(m[i],f[i]));
		}
		cout<<ans*2<<endl;
	}
	return 0;
}