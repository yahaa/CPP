#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100005;
const int maxx=1001;
int value[maxx],number[maxx],dp[maxn];
int kind,total;

void completePack(int cost,int weight){
	for(int j=cost;j<=total;j++)dp[j]=max(dp[j],dp[j-cost]+weight);
}

void zeroOnePack(int cost,int weight){
	for(int j=total;j>=cost;j--)dp[j]=max(dp[j],dp[j-cost]+weight);
}

void multiplyPack(int cost,int weight,int number){
	if(cost*number>=total)completePack(cost,weight);
	else {
		int k=1;
		while(k<number){
			zeroOnePack(k*cost,k*weight);
			number-=k;
			k<<=1;
		}
		zeroOnePack(number*cost,number*weight);
	}
}
int main(){
	while(cin>>kind>>total&&kind&&total){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=kind;i++)cin>>value[i];
		for(int i=1;i<=kind;i++)cin>>number[i];

		for(int i=1;i<=kind;i++)multiplyPack(value[i],value[i],number[i]);
		int ans=0;
	   for(int i=1;i<=total;i++)if(dp[i]==i)ans++;
	  cout<<ans<<endl;
	}
	return 0;
}