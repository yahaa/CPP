#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double k,a,b,max,min;
	while(cin>>k>>a>>b){
		max=pow(2,k-1)-1;
		min=-pow(2,k-1);
		if(a+b>=min&&a+b<=max)cout<<"WaHaHa"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}