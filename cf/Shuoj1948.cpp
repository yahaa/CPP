#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=40005;
vector<pair<int,int>>maps[maxn];
ll disIndex[maxn];
int vistIndex[maxn];
void initVector(int n){
    for(int i=1;i<=n;i++)maps[i].clear();
}

void addEdg(int u,int v,int w){
    maps[u].push_back(make_pair(v,w));
}

void dfs(int n){
    for(int i=0;i<maps[n].size();i++){
        int nLink=maps[n][i].first;
        if(!vistIndex[nLink]){
            vistIndex[nLink]=1;
            disIndex[nLink]=disIndex[n]^maps[n][i].second;
            dfs(nLink);
        }
    }
}
int main(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
         int n,q;
         scanf("%d%d",&n,&q);
        memset(disIndex,0,sizeof(disIndex));
        memset(vistIndex,0,sizeof(vistIndex));
         initVector(n);
         n-=1;
        while(n--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdg(u,v,w);
            addEdg(v,u,w);
        }
        dfs(1);
          printf("Case %d:\n",tt++);
        while(q--){
            int star,end;
            scanf("%d%d",&star,&end);
            printf("%lld\n",(disIndex[star]^disIndex[end]));
        }
    }
}