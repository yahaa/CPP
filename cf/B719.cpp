/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
const int maxn=100000+5;
int dp[maxn];
int main(){
	MS(dp,0);
	int n;
	string s;
	cin>>n>>s;
	string s1=s,s2=s;
	for(int i=0;i<n;i++){
		if(i%2==0)s1[i]='b';
		else s1[i]='r';
	}

	for(int i=0;i<n;i++){
		if(i%2==0)s2[i]='r';
		else s2[i]='b';
	}
	// cout<<s1<<endl;
	// cout<<s2<<endl;

	int ans10=0,ans11=0,ans20=0,ans21=0;
	for(int i=0;i<n;i++){
		if(s[i]!=s1[i]){
			if(s[i]=='r')ans10++;
			else ans11++;
		}
		if(s[i]!=s2[i]){
			if(s[i]=='r')ans20++;
			else ans21++;
		}
	}
	// cout<<ans10<<" "<<ans11<<endl;
	// cout<<ans20<<" "<<ans21<<endl;
	int t1=max(ans10,ans11);
	int t2=max(ans20,ans21);
	cout<<min(t1,t2)<<endl;

	return 0;
}
