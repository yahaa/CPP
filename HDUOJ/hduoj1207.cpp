#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int INF=0X3FFFF;
double dp[65];
int main(){
	dp[1]=1;
	dp[2]=3;

	for(int i=3;i<65;i++){
		dp[i]=INF;
		for(int j=1;j<i;j++){
			dp[i]=min(dp[i],2*dp[j]+pow(2.0,i-j)-1);
		}
	}
	int n;
	while(cin>>n){
		cout<<dp[n]<<endl;
	}
	return 0;
}