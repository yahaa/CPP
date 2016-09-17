/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
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
struct node{
	int i,v;
};
const int maxn=100005;
node lefts[maxn];
node rights[maxn];
bool cmp(node a,node b){
	return a.i<b.i;
}

int main(){
	int n,l=0,r=0,index,v;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&index,&v);
		if(index<0){
			lefts[l].i=-index;
			lefts[l++].v=v;
		}
		else {
			rights[r].i=index;
			rights[r++].v=v;
		}
	}
	sort(lefts,lefts+l,cmp);
	sort(rights,rights+r,cmp);
	int ans=0;
	if(l<r){
		for(int i=0;i<l;i++){
			ans+=lefts[i].v;
		}
		for(int i=0;i<=l;i++){
			ans+=rights[i].v;
		}
	}
	else if(l==r) {
		for(int i=0;i<r;i++){
			ans+=lefts[i].v;
		}
		for(int i=0;i<r;i++){
			ans+=rights[i].v;
		}
	}
	else {
		for(int i=0;i<r;i++){
			ans+=rights[i].v;
		}
		for(int i=0;i<=r;i++){
			ans+=lefts[i].v;
		}
	}
	cout<<ans<<endl;
	return 0;
}
