/*************************************************************************
	> File Name: hdu1164.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月07日 星期日 19时43分05秒
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
const int maxn=66666;
bool prime[maxn];
int p[300];

void getPrime(){
	MS(prime,true);
	MS(p,0);
	int index=0;
	for(int i=2;i<=sqrt(maxn);i++){
		if(prime[i]){
			p[index++]=i;
			for(int j=i+i;j<maxn;j+=i){
				prime[j]=false;
			}
		}
	}
}


int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	getPrime();
	int n;
	while(cin>>n){
		int t=0;
		for(int i=0;p[i]*p[i]<=n;i++){
			if(n%p[i]==0){
				while(n%p[i]==0){
					if(t==0)cout<<p[i];
					else cout<<"*"<<p[i];
					n/=p[i];
					t++;
				}
			}
		}
		if(n>1){
			if(t)cout<<"*"<<n;
			else cout<<n;
		}
		cout<<endl;
	}

	return 0;
}

