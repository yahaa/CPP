/*************************************************************************
	> File Name: baidud.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月14日 星期六 13时01分05秒
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
#define MS(a,x) memset(a,x,sozeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	cin>>n;
	string s;
	map<string,int>mp;
	for(int i=0;i<n;i++){
		cin>>s;
		sort(s.begin(),s.end());
		printf("%d\n",mp[s]++);
	}

	return 0;
}

