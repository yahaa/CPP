#include <iostream>    //01 背包问题
#include <algorithm>   //解题思路 f(i,v)=max(f(i-1,v),f(i-1,v-value[i])+weight[i]); 
#include <cstring>     //动态转移方程
using namespace std;
typedef long long ll;
const int maxn=1002;
ll dp[maxn][maxn];
ll value[maxn],weight[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int  n,v;
		cin>>n>>v;
		for(int i=1;i<=n;i++)cin>>weight[i];
		for(int i=1;i<=n;i++)cin>>value[i];
		for(int i=1;i<=n;i++){
			for(int j=v;j>=0;j--){
				if (j>=value[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-value[i]]+weight[i]);    
				else dp[i][j]=dp[i-1][j];
			}
		}

		for(int i=0;i<=n;i++)  //测试输出 与答案无关
			for(int j=0;j<=v;j++){
				if(j!=v)cout<<dp[i][j]<<" ";
				else cout<<dp[i][j]<<endl;
			}
		cout<<dp[n][v]<<endl;
	}
	return 0;
}