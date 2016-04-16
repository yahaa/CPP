#include <iostream>     //多重背包问题　　转换成　　01 背包问题
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100005;
const int maxx=1001;
int value[maxx],number[maxx],dp[maxn];
int kind,total;

void completePack(int cost,int weight){  //　　转换成二进制　　　可以降低时间复杂度　Ｏ(n*lognumber[i]);
	for(int j=cost;j<=total;j++)dp[j]=max(dp[j],dp[j-cost]+weight);
}

void zeroOnePack(int cost,int weight){
	for(int j=total;j>=cost;j--)dp[j]=max(dp[j],dp[j-cost]+weight);
}

void multiplyPack(int cost,int weight,int number){
	if(cost*number>=total)completePack(cost,weight);    //如果cost*number>=total 那么就可以把　多重背包当做完全背包处理
	else {                                              //所以出现了　调用完全背包的函数
		int k=1;
		while(k<number){
			zeroOnePack(k*cost,k*weight);              //否这用二进制的思想　　把多个物品用　０１背包来处理
			number-=k;
			k<<=1;
		}
		zeroOnePack(number*cost,number*weight);   //这里是处理最后剩下的　　物品
	}
}
int main(){
	while(cin>>kind>>total&&kind&&total){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=kind;i++)cin>>value[i];
		for(int i=1;i<=kind;i++)cin>>number[i];

		for(int i=1;i<=kind;i++)multiplyPack(value[i],value[i],number[i]);    //这里相当于０１背包的第一层循环
		int ans=0;
	   for(int i=1;i<=total;i++)if(dp[i]==i)ans++;
	  cout<<ans<<endl;
	}
	return 0;
}