#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=101;
int dp[maxn];
int main(){
	int need,total,kind,kills;
	while(cin>>need>>total>>kind>>kills){
		memset(dp,0,sizeof(dp));
		int value,weight;
		int count=0;
		int t=0;
		int flag=0;
		for(int i=1;i<=kind;i++){
			cin>>value>>weight;
			for(int j=0;j<=total;j++){
				if(j>=weight){
					int tt=dp[j];
					dp[j]=max(dp[j],dp[j-weight]+value);
					if(dp[j]>tt&&dp[j]<=need&&!flag){
						count++;
						t+=weight;
					}
					if(dp[j]>=need&&count<=kills)flag=1;
				}
			}
		}

	if(flag)cout<<total-t<<endl;
	else cout<<-1<<endl;
	}
	return 0;
}