#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dp[11][100000];
int in[11][100000];
int main(){
	int n;
	int x,ti;
	int maxti;
	while(cin>>n&&n){
		memset(dp,0,sizeof(dp));
		memset(in,0,sizeof(in));
		maxti=0;
		for(int i=1;i<=n;i++){
			cin>>x>>ti;
			maxti=max(maxti,ti);
			in[x][ti]++;
		}
		for(ti=1;ti<=maxti;ti++){
			for(int xi=0;xi<11;xi++){
				if(abs(xi-5)>ti){
					dp[xi][ti]=0;
				}
				else{
					if(xi==0){
						dp[0][ti]=max(dp[1][ti-1]+in[0][ti],dp[0][ti-1]+in[0][ti]);
					}
					else if(xi==10){
						dp[10][ti]=max(dp[9][ti-1]+in[10][ti],dp[10][ti-1]+in[10][ti]);
					}
					else{
						dp[xi][ti]=max(dp[xi][ti-1]+in[xi][ti],max(dp[xi+1][ti-1]+in[xi][ti],dp[xi-1][ti-1]+in[xi][ti]));
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<11;i++){
			ans=max(ans,dp[i][maxti]);
		}
		cout<<ans<<endl;
	}
	return 0;
}



// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// int dp[11][100010];
// int a[11][100010];

// int main(){
// 	int T;
// 	while(cin>>T&&T){
// 		memset(dp,0,sizeof(dp));
// 		memset(a,0,sizeof(a));
// 		int t=0;
// 		for(int i=0;i<T;i++){
// 			int m,n;
// 			scanf("%d%d",&m,&n);
// 			a[m][n]+=1;
// 			if(t<n)t=n;
// 		}
// 		int st=5;
// 		for(int i=1;i<=t;i++){
// 			for(int j=0;j<=10;j++){
// 				if(abs(j-st)>i)dp[j][i]=0;
// 				else{
// 					if(j==0){
// 						dp[0][i]=max(dp[1][i-1]+a[0][i],dp[0][i-1]+a[0][i]);
// 					}
// 					else if(j==10){
// 						dp[10][i]=max(dp[9][i-1]+a[10][i],dp[10][i-1]+a[10][i]);
// 					}
// 					else{
// 						dp[j][i]=max(dp[j][i-1]+a[j][i],max(dp[j+1][i-1]+a[j][i],dp[j-1][i-1]+a[j][i]));
// 					}
// 				}
// 			}
// 		}
// 		int ans=0;
// 		for(int i=0;i<11;i++)ans=max(ans,dp[i][t]);
// 		printf("%d\n",ans);
// 	}
// 	return 0;
// }