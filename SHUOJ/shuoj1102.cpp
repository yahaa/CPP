#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int G[10][10],counts[10],ans[35];

void init(){
	memset(G,0,sizeof(G));
	memset(counts,0,sizeof(counts));
	for(int i=0;i<=9;i++)G[i][i]=1;
	memset(ans,0,sizeof(ans));
	ans[0]=1;
}

void floyd(){
	for(int k=0;k<10;k++)
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++){
				if(G[i][k]&&G[k][j])G[i][j]=1;
			}
}

void getCount(){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			if(G[i][j])counts[i]++;
		}
}

void getAns(string s){
	int len=1;
	for(int i=0;i<s.length();i++){
		int x=counts[s[i]-'0'];
		int ins=0;
		for(int j=0;j<len;j++){
			ans[j]=ans[j]*x+ins;
			ins=ans[j]/10;
			ans[j]%=10;
		}
		do{
			if(ins>0)ans[len++]=ins%10;
			ins/=10;
		}while(ins>=10);
	}
	for(int i=len-1;i>=0;i--)cout<<ans[i];
	cout<<endl;
}

int main(){
	string s;
	int n,a,b;
	while(cin>>s>>n){
		init();
		for(int i=0;i<n;i++){
			cin>>a>>b;
			G[a][b]=1;
		}
		floyd();
		getCount();
		getAns(s);
	}
	return 0;
}