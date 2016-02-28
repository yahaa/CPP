#include <iostream>
using namespace std;
int main(){
	int d1,h1,m1,s1,d,h,m,s;
	int sd,sh,sm,ss;
	while(cin>>d>>h>>m>>s>>d1>>h1>>m1>>s1){
		sd=d+d1;
		sh=h+h1;
		sm=m+m1;
		ss=s+s1;
		int t1=ss/60;
		ss=ss%60;
		sm+=t1;
		t1=sm/60;
		sm=sm%60;
		sh+=t1;
		t1=sh/24;
		sh=sh%24;
		sd+=t1;
		cout<<sd<<" "<<sh<<" "<<sm<<" "<<ss<<endl;
	}
	return 0;
}