#include <bits/stdc++.h>
using namespace std;
const int maxn=3*100000+1;
int a[maxn];
int main(){
	int n;
	vector<pair<int,int> >ans;
	scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int s=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=i;
				while(a[t]!=a[j]&&t<j){
					// ans.push_back(make_pair(s,j));
					// s=j+1;
					// i=j;
					t++;
					// break;
				}
				if(t<j){
					ans.push_back(make_pair(s,j));
					s=j+1;
					i=j;
					break;
				}
			}
		}
		if(ans.size()==0)printf("-1\n");
		else{
			printf("%d\n",ans.size());
		for(int i=0;i<ans.size()-1;i++)printf("%d %d\n",ans[i].first,ans[i].second);
			printf("%d %d\n",ans[ans.size()-1].first,n);
		}
	return 0;
}