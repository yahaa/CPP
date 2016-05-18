#include <iostream>     //哈夫曼树   哈夫曼编码   
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int maxn=1280005;
int lch[130],rch[130];
int dp[maxn];

void init(){  //初始化函数
	memset(lch,0,sizeof(lch));
	memset(rch,0,sizeof(rch));
}

int main(){
	int t;
	cin>>t;
	int n,m,e;
	while(t--){
		init();
		priority_queue<int,vector<int>,greater<int> >qu;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>m;
			qu.push(m);
		}

		cin>>e;
		int left=e;
		int sum=0;
		int si=0;
		while(qu.size()!=1){
		　　　　//核心的重点还是 
			//叶节点权值乘上到根节点到该叶节点上的路径上的０的个数ci的和,,fi*ci＝li
			//打印出　每次构造哈弗曼树的左子树就会发现规律
			int l=qu.top();
			qu.pop();
			int r=qu.top();
			qu.pop();
			qu.push(l+r);//因为哈弗曼树没有交换之前一定是最小的
			left-=l;    //所以　left 表示E 减去最小情况下，还剩余多少
			sum+=r-l;  //因为哈弗曼书中左子树总是比右子树小
			lch[si]=l;  //所以sum 表示哈弗曼树左右子树中全部交换后还能增加多少
			rch[si++]=r;
		}
     
		if(left<0||left>sum){
			cout<<"No"<<endl;
			continue;
		}
       	memset(dp,0,sizeof(dp));
       	dp[0]=1;
       	for(int i=0;i<si;i++){
       		int le=rch[i]-lch[i];
       		for(int j=left;j>=le;j--){
       			if(dp[j-le])dp[j]=1;
       		}
       	}
       	
        if(dp[left])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
	}
	return 0;
}