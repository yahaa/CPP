#include <iostream>
#include <algorithm>
using namespace std;        //beffman_ford 适用于单源且不存在负回路　　　有向无向都适用　
const int maxn=101;
const int INF = 0x3FFFFFFF;
typedef struct Edge{
	int u, v，weight;  //起点，终点，边长
}Edge;

Edge edge[maxn];     // 保存边的值
int  dist[maxn];     // 结点到源点最小距离
int nodenum, edgenum, source;    // 结点数，边数，源点

void init(){   // 初始化图
	cin >> nodenum >> edgenum >> source;  // 输入结点数，边数，源点
	for(int i=1; i<=nodenum; ++i)dist[i] =INF;
	dist[source] = 0;
	for(int i=1; i<=edgenum; ++i){
		cin >> edge[i].u >> edge[i].v >> edge[i].weight;
	}
}

bool Bellman_Ford(){
	for(int i=1; i<=nodenum-1; ++i)
		for(int j=1; j<=edgenum; ++j)    // 松弛计算
		dist[edge[j].v]=min(dist[edge[j].v],dist[edge[j].u]+edge[j].weight);
			
	bool flag =true;
	for(int i=1; i<=edgenum; ++i)     // 判断是否有负环路
		if(dist[edge[i].v] > dist[edge[i].u] + edge[i].weight){
			flag =false;
			break;
		}
	return flag;
}
int main(){
    init();
	if(Bellman_Ford())
		for(int i = 1 ;i <= nodenum; i++)cout << dist[i] << endl;
	return 0;
}
