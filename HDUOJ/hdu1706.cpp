#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int g[101][101];
int a[101][101];
int n,m;
const int maxn=0X3f3f3f3f;
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(g[i][k]>=maxn||i==k)continue;
			for(int j=1;j<=n;j++){
				if(g[k][j]>=maxn||i==j||j==k)continue;
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
					a[i][j]=a[i][k]*a[k][j];
				}
				else if(g[i][j]==g[i][k]+g[k][j]){
					a[i][j]+=a[i][k]*a[k][j];
				}
			}
		
		}
	}
}

void solve(){
	int ans=-1;
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(g[i][j]==maxn)continue;
			if(g[i][j]>ans){
				ans=g[i][j];
				count=a[i][j];
			}
			else if(ans==g[i][j]){
				count+=a[i][j];
			}
		}
	}
	printf("%d %d\n",ans,count);
}


int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(g,0x3f,sizeof(g));
		memset(a,0,sizeof(a));
		int i,j,v;
		while(m-->0){
			scanf("%d%d%d",&i,&j,&v);
			if(i==j)continue;
			if(g[i][j]>v){
				g[i][j]=g[j][i]=v;
				a[i][j]=a[j][i]=1;
			}
			else if(g[i][j]==v){
				a[i][j]++;
				a[j][i]++;
			}
		}
		floyd();
		solve();

	}

	return 0;
}
