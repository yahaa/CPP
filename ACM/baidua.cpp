/*************************************************************************
	> File Name: baidua.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月21日 星期六 15时59分04秒
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

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t;
	cin>>t;
	int tt=1;
	while(t--){
		int x,m,k,c;
		cin>>x>>m>>k>>c;
		int sum=0;
		ll mm=1;
		int f=0;
		int s=-1;
		for(int i=1;i<=m;i++){
			if(mm>k){
				if(s==-1)s=mm%k;
				if(mm%k==s)f++;
				sum+=mm%k;
				if(f==2)break;
			}
			else sum+=mm%k;
			mm*=10;
		}
		printf("Case #%d:\n",tt++);
		if(((x%k)*sum)%k==c)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}

