#include <iostream>     //分组背包　　　其实本质还是　　０１背包的问题
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=105;
int dp[maxn];
int group[maxn][maxn];
int main(){
	int n,m;   //n m 分别表示　　　有多少们课程　　　和总的天数
	while(cin>>n>>m&&n&&m){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)cin>>group[i][j];

		for(int i=1;i<=n;i++){    //对组号进行遍历
			for(int j=m;j>=0;j--){  //把每一组都当成０１　背包来处理　　

				for(int k=1;k<=m;k++){    //因为每一组只能取一个　　所以这一层循环相当于　比较取哪一个所得的利益更加大
					if(j>=k)dp[j]=max(dp[j],dp[j-k]+group[i][k]);  //最里面的这一层循环相当于
				}                                             //我们多重背包问题种的二进制分解比较取几个更加有利
			}
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}