#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=501;
int G[maxn][maxn];//邻接矩阵存储图
int degree[maxn];
int n,m;
vector<int>ans;

void init(){
	memset(G,0,sizeof(G));
	memset(degree,0,sizeof(degree));
	ans.clear();
}
void topological(){
	int k;
	for(int i=0;i<n;i++){
		k=0;
		for(int j=0;j<n;j++){
			if(degree[j]==0){
				k=j;
				ans.push_back(j);
				degree[j]--;
				break;
			}
		}
	
		for(int j=0;j<n;j++){
			if(G[k][j]){
				G[k][j]=0;
				degree[j]--;
			}
		}
	}
}

int main(){
	int a,b;
	while(cin>>n>>m){
		init();
		for(int i=1;i<=m;i++){
			cin>>a>>b;
			if(G[a][b]==0){//重边度数不能相加
				G[a][b]=1;
				degree[b]++;
			}
			
		}
		topological();
		for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<" ";
		cout<<ans[ans.size()-1]<<endl;
	}
	return 0;
}


/*
6 9
1 0
1 4
4 0
0 2
0 3
2 3
5 3
5 2
5 4

9 11
2 5
2 4
2 3
1 3
1 8
3 4
8 9
9 7
4 7
5 6
4 6

6 9
1 0
3 0
2 0
1 3
2 3
4 2
4 3
4 5
3 5
*/

/*两种
1 5 4 0 2 3
5 1 4 0 2 3
*/
