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
bool cmp(int a,int b){
	return a>b;
}
int main(){
	string s;
	int k,a[27];
	cin>>s>>k;
	int n=s.length();
	for(int i=1;i<=26;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int t=s[i-1]-'a'+1;
		ans+=i*a[t];
	}
	int maxn=-10000;
	for(int i=1;i<=26;i++){
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=k;i++){
		ans+=maxn*(i+n);
	}
	cout<<ans<<endl;
	return 0;
}
