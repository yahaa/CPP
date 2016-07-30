/*************************************************************************
	> File Name: hdu1538.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月29日 星期五 17时21分20秒
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

void getNext(string pat,int *next){
	next[0]=-1;
	int j=0,k=-1;
	while(j<pat.length()){
		if(k==-1||pat[j]==pat[k])next[++j]=++k;
		else k=next[k];
	}
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	string s;
	int k=1;

	while(scanf("%d",&n)&&n){
		cin>>s;
		int *next=new int[s.length()+1];
		getNext(s,next);
		printf("Test case #%d\n",k++);
		for(int i=1;i<=n;i++){
			int j=i-next[i];
			if(i%j==0&&next[i])printf("%d %d\n",i,i/j);
		}
		printf("\n");
	}

	return 0;
}

