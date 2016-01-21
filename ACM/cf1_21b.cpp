#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int base[]={6,2,5,5,4,5,6,3,7,6};
	int a,b;
	while(cin>>a>>b){
		int ans=0;
		for(int i=a;i<=b;i++){
			int ti=i;
			do{
				ans+=base[ti%10];
				ti/=10;
			}while(ti>0);
		}
		cout<<ans<<endl;
	}
	return 0;
}