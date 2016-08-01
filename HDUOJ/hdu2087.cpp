/*************************************************************************
	> File Name: hdu2087.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月29日 星期五 10时26分35秒
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
vector<int>ans;

void getNext(const string &pat,int*next){
	next[0]=-1;
	int m=pat.length();
	int k=-1,j=0;
	while(j<m){
		if(k==-1||pat[k]==pat[j])next[++j]=++k;
		else k=next[k];
	}

}

void kmp(const string &ob,const string &pat){
	ans.clear();
	int n=ob.length();
	int m=pat.length();
	int *next=new int[m+1];
	getNext(pat,next);
	int i=0,j=0;
	
	while(i<n&&n-i>=m){
		while(j<m&&i<n){
			if(j==-1||pat[j]==ob[i]){
				i++;
				j++;
			}
			else j=next[j];
		}
		if(j<m){
			delete []next;
			return;
		}
		ans.push_back(i-j);
		j=0;
	}
	delete []next;
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	string ob,pat;
	while(true){
		cin>>ob;
		if(ob=="#")break;
		cin>>pat;
		kmp(ob,pat);
		cout<<ans.size()<<endl;
	}

	return 0;
}

