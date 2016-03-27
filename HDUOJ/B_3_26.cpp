#include <iostream>
using namespace std;
typedef long long ll;
int a[1000000];
int main(){
	ll n,x;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		ll tx=x;
		int ans=x;
		int i=0;
		do{
			a[i++]=tx%((ll)pow(10,n));
			tx/=(ll)pow(10,n);
		}while(tx>0);


	}

}