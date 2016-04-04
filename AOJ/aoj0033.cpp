#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int a[10];
bool ans;
void dfs(int i,int r,int l){
	if(i==10)return;
	if(ans==0)return;
	if(r<a[i])dfs(i+1,a[i],l);
	else if(l<a[i])dfs(i+1,r,l);
	else ans=0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<10;i++)cin>>a[i];
		dfs(0,0,0);
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	}
}