
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1005];
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int ans=0;
		int i;
		for(i=n-1;i>=3;i-=2)ans+=min(a[0]+2*a[1]+a[i], 2*a[0]+a[i]+a[i-1]);
		if(i==0)ans+=a[0];
		else if(i==1)ans+=a[i];
		else ans+=(a[2]+a[1]+a[0]);
		cout<<ans<<endl;
	}
}