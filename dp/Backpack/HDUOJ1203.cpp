#include <iostream>
#include <algorithm>   //01 背包小小变形      01 背包的两种问法     
#include <cstdio>      //如果是第一种问法，要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-∞，
using namespace std;    //如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。
const int maxn=10005;
double dp[maxn];
int main(){
	int total,m;
	while(cin>>total>>m&&(total||m)){    //输入的最后有两个0。按题意是m!=0&&n!=0 ,而实际上n||m才能过。。
		for(int i=0;i<maxn;i++)dp[i]=1.0;
		int value;
		double p;
		for(int i=1;i<=m;i++){
			cin>>value>>p;
			for(int j=total;j>=value;j--){   //滚动数组  求解01 背包问题， 用二维数组做会挂空间
				dp[j]=min(dp[j],dp[j-value]*(1.0-p));
			}
		}
		printf("%.1f%%\n",(1.0-dp[total])*100);
	}
	return 0;
}