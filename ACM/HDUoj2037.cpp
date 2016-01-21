#include <iostream>      //贪心   ，区间不相交的 个数最多
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=25;
bool cmp(pair<int ,int>a,pair<int ,int>b){
	return a.second<b.second;
}
int main(){
	int n;
	vector<pair<int,int> >a;
	while(cin>>n&&n){
		a.clear();
		for(int i=0;i<n;i++){
			int s,e;
			cin>>s>>e;
			a.push_back(make_pair(s,e));
		}
		sort(a.begin(), a.end(),cmp);
		int ans=1;
		int te=a[0].second;
		for(int i=1;i<a.size();i++){
			if(a[i].first>=te){
				ans++;
				te=a[i].second;
			}
		}
		cout<<ans<<endl;	
	}
}