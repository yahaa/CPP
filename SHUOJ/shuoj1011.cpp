#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int a[21];
int n,k;
int ans;


int isprime(int s){
	int nn=(int)sqrt(s);
	for(int i=2;i<=nn;i++){
		if(s%i==0)return 0;
	}
	return 1;
}
void init(){
	ans=0;
}

void dfs(int sum,int i,int cur){
	if(i>=n)return;
	if(cur==k)ans+=isprime(sum);
	if(cur<k){
		dfs(sum,i+1,cur);
		dfs(sum+a[i+1],i+1,cur+1);
	}
	
}
int main(){
	while(cin>>n>>k){
		init();
		for(int i=0;i<n;i++)cin>>a[i];
		dfs(0,-1,0);
		cout<<ans<<endl;
	}
	return 0;

}