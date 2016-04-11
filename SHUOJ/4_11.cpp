// #include <iostream>    //01 背包问题
// #include <algorithm>   
// #include <cstring>     
// using namespace std;
// typedef long long ll;
// const int maxn=1002;
// ll f[maxn];
// int main(){
// 	int total,m;
// 	int ti,v;
// 	while(cin>>total>>m){
// 		memset(f,0,sizeof(f));
// 		for(int i=1;i<=m;i++){  
// 			cin>>ti>>v;
// 			for(int j=total;j>=ti;j--){
// 				f[j]=max(f[j],f[j-ti]+v);
// 			}
// 		}
// 		cout<<f[total]<<endl;
// 	}
// 	return 0;
// }

//F
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main(){
// 	int a[12];
// 	int sum,save;
// 	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10]>>a[11]){
// 		sum=0;
// 		save=0;
// 		int f=-1;
// 		for(int i=0;i<12;i++){
// 			sum+=300-a[i];
// 			if(sum<0){
// 				f=i;
// 				break;
// 			}
// 			save+=(sum/100)*100;
// 			sum%=100;
// 		}
// 		if(f>=0)cout<<-(f+1)<<endl;
// 		else cout<<save*(1+0.2)+sum<<endl;

// 	}
// 	return 0;
// }


#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
int G[11][11];
int vis[11];
int n;
int vs;
int d;
void dfs(int v){
	if(vs==n+1){
		if(G[v][0])d=1;
		return;
	}
	for(int i=0;i<=n;i++){
		if(G[v][i]&&!vis[i]){
			vis[i]=1;
			vs++;
			dfs(i);
			vis[i]=0;
			vs--;
		}
	}
}
int main(){
	
	string s;
	int t=1;
	while(cin>>n&&n){
		getchar();
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			getline(cin, s);
			stringstream ss(s);
			int e;
			while(ss>>e){
				if(!G[i][e]){
					G[i][e]=1;
					G[e][i]=1;
				}
			}
		}
		d=0;
		vs=1;
		vis[0]=1;
		dfs(0);
		if(d)printf("Case %d: Granny can make the circuit.\n",t++);
		else printf("Case %d: Granny can not make the circuit.\n",t++);
	}
	return 0;
}

