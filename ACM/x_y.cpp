/*************************************************************************
	> File Name: x_y.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月21日 星期六 19时41分13秒
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
	ll n;
	while(t--){
		scanf("%lld",&n);
		if(n%2){
			if(n==1)cout<<"False"<<endl;
			else cout<<"True"<<endl;
		}
		else {
			if(n%4==0){
				if(n==4)cout<<"False"<<endl;
				else cout<<"True"<<endl;
			}
			else cout<<"False"<<endl;
		}
	}
	return 0;
}

