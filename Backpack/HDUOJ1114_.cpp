#include <iostream>    //完全背包  二维数组实现  
#include <algorithm>    //这个写法并不能解出这题 ，因为时间超时
#include <cstdio>        //写这个解法是为了练习怎么写 完全背包二维数组实现
using namespace std;
const int maxn=10005;
const int INF=100000000;
int f[maxn][maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<maxn;i++){  //这一步初始化的时候消耗了大量的时间
			for(int j=0;j<maxn;j++){
				if(i==0&&j==0)f[i][j]=0;
				else f[i][j]=INF;
			}
		}
		int empty,full;
		cin>>empty>>full;
		int total=full-empty;
		int n;
		cin>>n;
		int value,weight;
		for(int i=1;i<=n;i++){       //动态规划公式   f[i][j]=max(f[i-1][j],f[i-1][j-vi]+wi)
			cin>>value>>weight;         //其中   f[i-1][j] 表示  第 i 件物品 没有出现在背包中时f[i][j] 的最优解
			for(int j=0;j<=total;j++){   // 最关键的还是   [i-1] 表示 i  没有放入背包中    [i]  表示背包中  最少一个 i
				if(j>=weight)f[i][j]=min(f[i-1][j],f[i][j-weight]+value);   
				else f[i][j]=f[i-1][j];
			}
		}

		if(f[n][total]==INF)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<f[n][total]<<"."<<endl;
	}
	return 0;
}

//具体请看大神博客http://blog.csdn.net/wumuzi520/article/details/7014830