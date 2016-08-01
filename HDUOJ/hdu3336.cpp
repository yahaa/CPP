/*************************************************************************
	> File Name: hdu3336.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月29日 星期五 14时20分01秒
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
const int mod=10007;

void getNext(const string &pat,int*next){
	int n=pat.length();
	next[0]=-1;
	int i=0,k=-1;
	while(i<n){
		if(k==-1||pat[k]==pat[i])next[++i]=++k;
		else k=next[k];
	}
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t;
	cin>>t;
	int n;
	string s;
	int *next;
	while(t--){
		cin>>n;
		cin>>s;
		next=new int[n+1];
		getNext(s,next);
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=i;
			while(j){
				ans+=1;
				ans%=mod;
				j=next[j];
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

