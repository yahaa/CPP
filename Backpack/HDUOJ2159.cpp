#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=101;
int dp[maxn][maxn];
int main(){
	int need,total,kind,kills;
	while(cin>>need>>total>>kind>>kills){
		memset(dp,0,sizeof(dp));
		int value,weight;
		for(int i=1;i<=kind;i++){
			cin>>value>>weight;
			for(int j=weight;j<=total;j++){   //二维　　　完全背包　　分别对　　j  k 遍历把问题转换成完全背包的形式
				for(int k=1;k<=kills;k++){
					dp[j][k]=max(dp[j][k],dp[j-weight][k-1]+value);
				}
			}
		}

		int ans,flag=0;    //根据题目的问法　，遍历找出答案
		for(int i=1;i<=total;i++){
			for(int j=1;j<=kills;j++){
				if(dp[i][j]>=need){
					ans=i;
					flag=1;
					break;
				}
			}
			if(flag==1)break;
		}

		if(flag)cout<<total-ans<<endl;
		else cout<<-1<<endl;
			
	}
	return 0;
}