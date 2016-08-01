/*************************************************************************
	> File Name: hdu2594_kmp.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月01日 星期一 17时28分24秒
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

void getNext(string s,int *next){
	next[0]=-1;
	int j=0;
	int k=-1;
	while(j<s.length()){
		if(k==-1||s[j]==s[k])next[++j]=++k;
		else k=next[k];
	}
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	string s1,s2;
	while(cin>>s1>>s2){
		int n=s1.length()+s2.length();
		int *next=new int [n+1];
		getNext(s1+s2,next);
		int len=n;
		while(len>s1.length()||len>s2.length())len=next[len];
		if(len==0)cout<<0<<endl;
		else{
			for(int i=0;i<len;i++)cout<<s1[i];
			cout<<" "<<len<<endl;
		}
	}

	return 0;
}

