/*************************************************************************
	> File Name: shu_2033.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月10日 星期二 12时52分24秒
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

struct job{
	int j;
	int p;
	bool f;
};

int pri[10];
int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		MS(pri,0);
		queue<job>qu;
		int n,pos,p;
		cin>>n>>pos;
		for(int i=0;i<n;i++){
			cin>>p;
			job tj;
			tj.j=i;
			tj.p=p;
			if(i==pos)tj.f=1;
			else tj.f=0;
			pri[p]++;
			qu.push(tj);
			
		}
		bool fg=1;
		int ans=0;
		while(fg&&!qu.empty()){
			job ou;
			ou.j=qu.front().j;
			ou.p=qu.front().p;
			ou.f=qu.front().f;
			qu.pop();
			int sum=0;
			for(int i=9;i>ou.p;i--)if(pri[i]>0)sum+=pri[i];
			if(sum>0)qu.push(ou);
			else {
				pri[ou.p]--;
				ans++;
				if(ou.f)fg=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

