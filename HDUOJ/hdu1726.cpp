#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF=10000000;
string s;
const int mx=105;
int ish[mx][mx];
int dp[mx];

bool isp(string st){
	for(int i=0,j=st.length()-1;i<j;j--,i++){
		if(st[i]!=st[j])return false;
	}
	return true;
}

void init(){
	for(int i=1;i<s.length();i++)dp[i]=INF;
	memset(ish,0,sizeof(ish));
	for(int i=0;i<s.length();i++){
		for(int j=i;j<s.length();j++){
			if(isp(s.substr(i,j-i+1)))ish[i][j]=1;
			else ish[i][j]=0;
		}
	}
}


int main(){
	
	while(cin>>s){
		init();
		dp[0]=0;
		for(int i=1;i<s.length();i++){
			if(ish[0][i])dp[i]=0;
			else {
				for(int j=0;j<i;j++){
					if (ish[j + 1][i])
                        dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
		
		cout<<dp[s.length()-1]<<endl;
	}
	return 0;
}