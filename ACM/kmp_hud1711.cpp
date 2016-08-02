/*************************************************************************
	> File Name: hud1711.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月29日 星期五 15时36分51秒
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
int n,m;
int ob[1000001];
int pat[10001];
void getNext(int*next){
	next[0]=-1;
	int k=-1,j=0;
	while(j<m-1){
		if(k==-1||pat[k]==pat[j])next[++j]=++k;
		else k=next[k];
	}

}

int kmp(){
	int *next=new int[m];
	getNext(next);
	int i=0,j=0;

	while(j<m&&i<n){
		if(j==-1||pat[j]==ob[i]){
			i++;
			j++;
		}
		else j=next[j];
	}
	delete []next;
	if(j<m)return -1;
	return i-j+1;
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&ob[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&pat[i]);
		}
		printf("%d\n",kmp());
		
	}

	return 0;
}

