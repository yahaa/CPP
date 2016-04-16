#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=105;
int dp[maxn];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int total,kind;
		cin>>total>>kind;
		int price,weight,count;
		for(int i=1;i<=kind;i++){
			cin>>price>>weight>>count;
			for(int j=1;j<=count;j++){    //多重背包转化成01  背包求解     同理   完全背包  count=total/price 
				for(int k=total;k>=price;k--){
					dp[k]=max(dp[k],dp[k-price]+weight);
				}
			}
		}
		cout<<dp[total]<<endl;
	}
	return 0;
}