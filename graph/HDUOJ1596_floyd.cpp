#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=1001;
double G[maxn][maxn];

void init(int n){
	memset(G,0,sizeof(G));
}

void floyd(int n){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if(G[i][k]!=0)
			for(int j=1;j<=n;j++)G[i][j]=max(G[i][j],G[i][k]*G[k][j]);
}

int main(){
	int n,q,a,b;
	while(scanf("%d",&n)!=EOF){
		init(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)scanf("%lf",&G[i][j]);

		floyd(n);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&a,&b);
			if(G[a][b]==0)printf("What a pity!\n");
			else printf("%.3f\n",G[a][b]);
		}
	}
	return 0;
}