#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1001;
int preant[maxn];
int n,m,ans;

void init(int n){
	for(int i=1;i<=n;i++)preant[i]=i;
	ans=n-1;
}

int find(int x){
	int r=x;
	while(preant[r]!=r)r=preant[r];

	int tr=x,tp;
	while(preant[tr]!=r){
		tp=preant[tr];
		preant[tr]=r;
		tr=tp;
	}
	return r;
}

void join(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		preant[x]=y;
		ans--;
	}
}

int main(){
	int a,b;
	while(scanf("%d",&n)&&n){
		scanf("%d",&m);
		init(n);
		while(m--){
			scanf("%d%d",&a,&b);
			join(a,b);
		}
		printf("%d\n",ans);
	}
	return 0;
}