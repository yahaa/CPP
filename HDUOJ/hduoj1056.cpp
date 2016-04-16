#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	double t;
	while(cin>>t&&t>0){
		double ans=0;
		int i;
		for(i=2;ans<t;i++){
				ans+=1.0/i;
		}
		printf("%d card(s)\n",i-2);
	}
	return 0;
}