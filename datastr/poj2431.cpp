#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=100005;
struct station{
	int dis,fule;
};

bool cmp(station a,station b){
	return a.dis<b.dis;
}

station sta[maxn];
int n,l,p;

void solve(){
	priority_queue<int>qu;
	int ans=0,pos=0,tank=p;
	for(int i=0;i<n;i++){
		int d=sta[i].dis-pos;
		while(tank-d<0){
			if(qu.empty()){
				cout<<-1<<endl;
				return;
			}
			tank+=qu.top();
			qu.pop();
			ans++;
		}
		tank-=d;
		pos=sta[i].dis;
		qu.push(sta[i].fule);
	}
	cout<<ans<<endl;
}
int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>l>>p;
			sta[i].dis=l;
			sta[i].fule=p;
		}
		cin>>l>>p;
		for(int i=0;i<n;i++)sta[i].dis=l-sta[i].dis;
		sta[n].dis=l;
		sta[n].fule=0;
		n++;
		sort(sta,sta+n,cmp);
		for(int i=0;i<n;i++){
			cout<<sta[i].dis<<"  "<<sta[i].fule<<endl;
		}
		solve();
	}
	return 0;
}