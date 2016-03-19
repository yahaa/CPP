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



#include <iostream>//shuta
#include <algorithm>
#include <cstring>
using namespace std;
int dp[11][100000];
int main(){
    int n;
    int x,ti;
    int maxti;
    while(cin>>n&&n){
        memset(dp,0,sizeof(dp));
        maxti=0;
        for(int i=1;i<=n;i++){
            cin>>x>>ti;
            maxti=max(maxti,ti);
            dp[x][ti]++;
        }
        for(ti=maxti-1;ti>=0;ti--){
            dp[0][ti]+=max(dp[1][ti+1],dp[0][ti+1]);
            for(int xi=1;xi<10;xi++)
                dp[xi][ti]+=max(dp[xi][ti+1],max(dp[xi+1][ti+1],dp[xi-1][ti+1]));
            dp[10][ti]+=max(dp[9][ti+1],dp[10][ti+1]);
        }
        cout<<dp[5][0]<<endl;
    }
    return 0;
}