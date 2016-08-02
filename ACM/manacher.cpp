/*************************************************************************
	> File Name: manacher_poj3974.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月01日 星期一 18时11分44秒
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

const int MAXN=1000005;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(string s){
	int len=s.length();
	int l=0;
	Ma[l++]='$';
	Ma[l++]='#';
	for(int i=0;i<len;i++){
		Ma[l++]=s[i];
		Ma[l++]='#';
	}
	Ma[l]=0;
	int mx=0,id=0;
	for(int i=0;i<l;i++){
		Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
		while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
		if(i+Mp[i]>mx){
			mx=i+Mp[i];
			id=i;
		}
	}
}

int main(){
	string s;
	while(cin>>s){
		if(s=="END")break;
		Manacher(s);
		int ans=0;
		for(int i=0;i<2*s.length()+2;i++)ans=max(ans,Mp[i]-1);
		printf("%d\n",ans);
	}
	return 0;
}
