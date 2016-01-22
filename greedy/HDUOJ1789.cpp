#include <iostream>    //贪心问题
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1001;
const int maxd=1000000;
int used[maxd];
struct task{
	int d,f;
};

bool cmp(task a,task b){           //  贪心策略    扣分多的优先考虑，   在扣分情况相同的情况下 优先考虑时间期限最短的
	if(a.f==b.f)return a.d<b.d;
	return a.f>b.f;
}
int main(){
	int t;
	cin>>t;
	task a[maxn];
	while(t--){
		int n;
		cin>>n;
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)cin>>a[i].d;
		for(int i=0;i<n;i++)cin>>a[i].f;
		sort(a,a+n,cmp);
		int ans=0;
		for(int i=0;i<n;i++){
			int j;
			for(j=a[i].d;j>0;j--){
				if(!used[j]){
					used[j]=1;
					break;
				}
			}
			if(j==0)ans+=a[i].f;
		}
		cout<<ans<<endl;
	}
	return 0;
}


