/* ***********************************************************
//二分图匹配(匈牙利算法的DFS实现)(邻接表实现)
//建立G[i][j]表示i->j的有向边就可以了,是左边向右边的匹配
//v1是匹配左边的顶点数,v2是匹配右边的顶点数
//调用:ans=bipartite_matching();输出最大匹配数
//优点:适用于稀疏图,DFS找增广路,实现简洁易于理解
//时间复杂度:O(VE)
*************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxv=405;
const int INF=0XFFFF;
<<<<<<< HEAD
int G[maxv][maxv];
=======
int p,n;
vector<int> G[maxv];
>>>>>>> 6bb618f4aa81f2442abc3bea5a833898e345055c
int match[maxv];
bool used[maxv];
int p,n;

<<<<<<< HEAD
int dfs(int u){
	for(int i=1;i<=n;i++){
		if(G[u][i]&&!used[i]){
			used[i]=1;
			if(!match[i]||dfs(match[i])){
				//match[u]=i;
				match[i]=u;
				return 1;
			}
		}
	}
	return 0;
=======
void add_edge(int u,int v){
	G[u].push_back(v);
}

bool dfs(int v){
	for(int i=0;i<G[v].size();i++){
		int u=G[v][i];
		if(!used[u]){
			used[u]=1;
			if(match[u]<0||dfs(match[u])){
				match[u]=v;
				return true;
			}
		}
	}
	return false;
}

int bipartite_matching(){
	int ans=0;
	memset(match,-1,sizeof(match));
	for(int i=1;i<=p;i++){
		memset(used,0,sizeof(used));
		if(dfs(i))ans++;
	}
	return ans;
}

void init(){
	for(int i=0;i<maxv;i++)G[i].clear();
>>>>>>> 6bb618f4aa81f2442abc3bea5a833898e345055c
}

int main(){
	int t;
	cin>>t;
<<<<<<< HEAD
	int count,vt;
=======
>>>>>>> 6bb618f4aa81f2442abc3bea5a833898e345055c
	while(t--){
		memset(G,0,sizeof(G));
		memset(match,0,sizeof(match));
		cin>>p>>n;
<<<<<<< HEAD
		for(int i=1;i<=p;i++){
			cin>>count;
			while(count--){
				cin>>vt;
				G[i][vt]=1;
				//G[vt][i]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=p;i++){
			memset(used,0,sizeof(used));
			if(dfs(i))ans++;
		}
=======
		int count,s;
		for(int i=1;i<=p;i++){
			cin>>count;
			while(count--){
				cin>>s;
				add_edge(i,s);
			}
		}
		int ans=bipartite_matching();
>>>>>>> 6bb618f4aa81f2442abc3bea5a833898e345055c
		if(ans==p)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}
	return 0;
<<<<<<< HEAD
=======
}



/* ***********************************************************
//二分图匹配(匈牙利算法的DFS实现)(邻接矩阵形式)
//初始化:G[][]两边顶点的划分情况
//建立G[i][j]表示i->j的有向边就可以了,是左边向右边的匹配
//G没有边相连则初始化为0
//v1是匹配左边的顶点数,v2是匹配右边的顶点数
//调用:ans=bipartite_matching();输出最大匹配数
//优点:适用于稠密图,DFS找增广路,实现简洁易于理解
//时间复杂度:O(VE)
*************************************************************/
//顶点编号从1开始的

#include <iostream>//匈牙利算法，邻接矩阵版
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxv=405;
int G[maxv][maxv];
int match[maxv];
bool used[maxv];
int v1,v2;
int dfs(int u){
    for(int i=1;i<=v2;i++){
        if(G[u][i]&&!used[i]){
            used[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}

int bipartite_matching(){
	int ans=0;
	memset(match,0,sizeof(match));//初始化为０　　说明点的编号是从１开始
    for(int i=1;i<=v1;i++){
        memset(used,0,sizeof(used));
        if(dfs(i))ans++;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    int p,n;
    int count,vt;
    while(t--){
        memset(G,0,sizeof(G));
        cin>>p>>n;
        v1=p;
        v2=n;
        for(int i=1;i<=v1;i++){
            cin>>count;
            while(count--){
                cin>>vt;
                G[i][vt]=1;
            }
        }
        int ans=bipartite_matching();
        if(ans==v1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;    
    }
    return 0;
>>>>>>> 6bb618f4aa81f2442abc3bea5a833898e345055c
}