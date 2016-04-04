#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=120000;
int dp[maxn];
int a[7];

void ZeroOne_Pack(int cost,int weight,int n){  
    for(int i=n; i>=cost; i--)  
        dp[i] = max(dp[i],dp[i-cost] + weight);  
}  
  
void Complete_Pack(int cost,int weight,int n){  
    for(int i=cost; i<=n; i++)  
        dp[i] = max(dp[i],dp[i-cost] + weight);  
}  
  
int Multi_Pack(int a[],int n,int m){  
	memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++){  
        if(i*a[i]> m)Complete_Pack(i,i,m);  
        else{  
            int k = 1;  
            while(k <a[i]){  
                ZeroOne_Pack(k*i,k*i,m);  
                a[i] -= k;
                k <<= 1;  
            }  
            ZeroOne_Pack(a[i]*i,a[i]*i,m);  
        }  
    }  
    return dp[m];  
}  

int main(){
	string s;
	int t=1;
	while(getline(cin,s)){
		stringstream ss(s);
		memset(a,0,sizeof(a));
		int n=1,total=0,x;
		while(ss>>x){
			total+=n*x;
			a[n++]=x;
		}
		if(total==0)break;
		if(total%2==1){
			printf("Collection #%d:\n",t++);
			printf("Can't be divided.\n\n");
		}
		else {
			total/=2;
			int ans=Multi_Pack(a,6,total);
			if(ans!=total){
				printf("Collection #%d:\n",t++);
				printf("Can't be divided.\n\n");
			}
			else{
				printf("Collection #%d:\n",t++);
				printf("Can be divided.\n\n");
			}
		}
	}
	return 0;
}