#include <iostream>
using namespace std;
int main(){
	int n,m;
	while(cin>>m>>n){
		int ans=1;
		for(int i=n-1;i>=1;i--)ans*=i;
		for(int i=n;i>n-m;i--)ans*=i;
		cout<<ans<<endl;
	}
	return 0;
}