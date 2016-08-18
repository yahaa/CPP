#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[105];
int n;
int solve(){
	int ans=0;
	
	while(n!=1){
		int t=10000000;
		int index=1;
		for(int i=1;i<n;i++){
			if(a[i]+a[i-1]<t){
				index=i;
				t=a[i]+a[i-1];
			}
		}
		ans+=t;
		a[index-1]=t;
		for(int j=index+1;j<n;j++){
			a[j-1]=a[j];
		}
		n--;
	}
	return ans;
}

int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		cout<<solve()<<endl;

	}
	return 0;
}