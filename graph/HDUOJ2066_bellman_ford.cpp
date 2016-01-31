#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1001;
const int INF=0x3FFFFFF;
struct grap{
	int s,e,length;
};

vector<grap>maps;
int dis[maxn];

void init(){
	maps.clear();
	for(int i=0;i<maxn;i++)dis[i]=INF;
	dis[0]=0;    //默认 0 是起点
}

bool Bellman_Ford(){
	int n=maps.size();
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)    // 松弛计算bellman_ford 算法的核心
		dis[maps[j].e]=min(dis[maps[j].e],dis[maps[j].s]+maps[j].length);
	bool flag=true;
	// for(int i=0;i<maps.size();i++){   //显然本题没有负数边存在　　所以不用判断是否有　　负权值回路
	// 	if(dis[maps[i].e]>dis[maps[i].s]+maps[i].length){
	// 		flag=false;
	// 		break;
	// 	}
	// }

	return flag;
}
int main(){
	int t,s,d,a,b,w;
	grap temp1,temp2;
	while(cin>>t>>s>>d){
		init();
		while(t--){
		cin>>a>>b>>w;    //无向图　，所以要添加双向边
		temp1.s=a;
		temp1.e=b;
		temp1.length=w;
		temp2.s=b;
		temp2.e=a;
		temp2.length=w;
		maps.push_back(temp1);
		maps.push_back(temp2);
		}
		int tt;
		while(s--){
			cin>>tt;
			temp1.s=0;
			temp1.e=tt;
			temp1.length=0;
			temp2.s=tt;
			temp2.e=0;
			temp2.length=0;
			maps.push_back(temp1);
			maps.push_back(temp2);
		}

		Bellman_Ford();
		int ans=INF;
		while(d--){
			cin>>tt;
			ans=min(ans,dis[tt]);
		}
		cout<<ans<<endl;
	}
	return 0;
}