/*************************************************************************
	> File Name: poj1200.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月31日 星期日 12时01分42秒
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
#include <fstream>
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
const int maxn=16e6+5;
bool hash[maxn];
int ch[256];

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n,nc;
	string s;
	while(cin>>n>>nc>>s){
		int ti=0;
		fill(ch,ch+256,-1);
		MS(hash,0);
		FOR(i,s.length()){
			if(ch[s[i]]==-1){
				ch[s[i]]=ti++;
			}
		}
		int temp=0;
		int ni=nc;
		FOR(i,n-1){
			temp=temp*nc+ch[s[i]];
			ni*=nc;
		}
		int ans=0;
		for(int i=n-1;i<s.length();i++){
			temp=(temp*nc+ch[s[i]])%ni;
			if(!hash[temp]){
				ans++;
				hash[temp]=1;
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}

