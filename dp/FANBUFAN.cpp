#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1000005][2];//dp[i][0]  A
int main(){			//dp[i][1]  B
	int n;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		string s,ts;
		cin>>s;
		ts+=" ";
		ts+=s;
		for(int i=1;i<=n;i++){
			dp[i][0]=min(dp[i-1][0]+(ts[i]=='B'),dp[i-1][1]+1+(ts[i]=='A'));
			dp[i][1]=min(dp[i-1][1]+(ts[i]=='A'),dp[i-1][0]+1+(ts[i]=='B'));
		}
		cout<<min(dp[n][0],dp[n][1]+1)<<endl;

	}
	return 0;
}