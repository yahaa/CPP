/*第一类题目
整数划分为　最大数　不超过k 的划分
dp[i][j]为ｉ划分为最大数不超过　j 的划分
　分析　　　　1.当　　j>i时　dp[i][j]=dp[i][i];
         2.当　 j=i时　dp[i][j]=1+dp[i][j-1];
         3.当　　j<i时分为两种情况　　a.划分数中出现　　j   和划分数中不出现　　j 所以dp[i][j]=dp[i-j][j]+dp[i][j-1];
*/
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int maxn=125;
// int dp[maxn][maxn];
// int main(){
// 	int n;
// 	while(cin>>n){
// 		dp[0][0]=0;
// 		for(int i=1;i<=n;i++){
// 			for(int j=1;j<=n;j++){
// 				if(j>i)dp[i][j]=dp[i][i];
// 				else if(i==j)dp[i][j]=1+dp[i][j-1];
// 				else dp[i][j]=dp[i-j][j]+dp[i][j-1];
// 			}
// 		}
// 		cout<<dp[n][n]<<endl;
// 	}
// 	return 0;
// }





// /*第二类
// 	将整数 j 划分为最多不超过　　i 组的划分
// 	分析：
// 	能划分，那么必须有每一项　ai>0,
// 	dp[i][j]为i 划分为不超过　j组的划分
// 	当　i>=j ,dp[i][j]中存在ai=0,和ai>0的情况　　dp[i][j]=dp[i-j][j]+dp[i][j-1];
// 	当　i<j ,dp[i][j]=dp[i][j-1];
// */
// #include <iostream>
// using namespace std;
// const int maxn=105;
// int dp[maxn][maxn];
// int main(){
// 	int n,m;//n个物品　，划分为不超过　　m 组
// 	while(cin>>n>>m){
// 		dp[0][0]=1;
// 		for(int i=1;i<=m;i++){//划分为的组数
// 			for(int j=0;j<=n;j++){//要划分的物品数
// 				if(i<=j)dp[i][j]=dp[i][j-i]+dp[i-1][j];
// 				else dp[i][j]=dp[i-1][j];
// 			}
// 		}
// 		cout<<dp[m][n]<<endl;
// 	}
// 	return 0;
// }




// /*第三类题与第一类题目很像
// 	设dp[i][j]为将i划分为不超过j的不同整数的划分数
// 	dp[i][j]为ｉ划分为最大数不超过　j 的划分
// 	分类讨论　　　1.当　　j>i时　dp[i][j]=dp[i][i];
//            2.当　 j=i时　dp[i][j]=1+dp[i][j-1];
//            3.当　　j<i时分为两种情况　　a.划分数中出现　　j   和划分数中不出现　　j 所以dp[i][j]=dp[i-j][j－１]+dp[i][j-1];
// */
// #include <iostream>
// using namespace std;
// const int maxn=105;
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int maxn=125;
// int dp[maxn][maxn];

// int main(){
// 	int n;
// 	while(cin>>n){
// 		dp[0][0]=0;
// 		for(int i=1;i<=n;i++){
// 			for(int j=1;j<=n;j++){
// 				if(j>i)dp[i][j]=dp[i][i];
// 				else if(i==j)dp[i][j]=1+dp[i][j-1];
// 				else dp[i][j]=dp[i-j][j-1]+dp[i][j-1];//与第一种的区别就是这一句
// 			}
// 		}
// 		cout<<dp[n][n]<<endl;
// 	}
// 	return 0;
// }




// /*第四类
// 将n划分为k个整数的划分数
// 设dp[i][j]为将i划分为j个整数的划分数
// 分析:
// 		a.i<j ,dp[i][j]=0;
// 		b.i=j ,dp[i][j]=1;
// 		c.i>j ,分为两类情况　划分中 ai >1,和划分中　ai=1 ,所以dp[i][j]=dp[i-j][j]+dp[i-1][j-1]
// */
// #include <iostream>
// using namespace std;
// const int maxn=125;
// int dp[maxn][maxn];
// int main(){
// 	int n,k;
// 	while(cin>>n>>k){
// 		dp[0][0]=0;
// 		for(int i=1;i<=n;i++){
// 			for(int j=1;j<=k;j++){
// 				if(i<j)dp[i][j]=0;
// 				else if(i==j)dp[i][j]=1;
// 				else dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
// 			}
// 		}
// 		cout<<dp[n][k]<<endl;
// 	}
// 	return 0;
// }




/*第五类
将n划分为若干正奇数之和的划分数
分析：
	1.设f[i][j]为将i划分为j个奇数之和的划分数
	2.g[i][j]为将i划分为j个偶数之和的划分数
	3.使用截边法，将g[i][j]的j个划分都去掉1，可以得到f[i-j][j]
	4.所以 g[i][j] = f[i-j][j]
	5.f[i][j]中有包含1的划分方案和不包含1的划分方案 所以f[i][j]=g[i-j][j]+f[i-1][j-1]
	6.f[n][0]+f[n][1]+……+f[n][n]为将n划分为若干奇数的划分数
*/
#include <iostream>
using namespace std;
const int maxn=105;
int f[maxn][maxn];
int g[maxn][maxn];

int main(){
	int n;
	while(cin>>n){
		f[0][0]=1;
		g[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				g[i][j]=f[i-j][j];
				f[i][j]=g[i-j][j]+f[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=0;i<=n;i++)ans+=f[n][i];
		cout<<ans<<endl;
	}
	return 0;
}
