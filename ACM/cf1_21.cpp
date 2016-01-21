#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2){
		int t1=abs(x1-x2);
		int t2=abs(y1-y2);
		int ans=min(t1,t2);
		ans+=abs(t1-t2);
		cout<<ans<<endl;
	}
}