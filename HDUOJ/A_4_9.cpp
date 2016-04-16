#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	int n,m;
	double alg1,alg2;
	while(t--){
		cin>>n>>m;
		alg1=(n-2)*180*1.0/n;
		alg2=(m-2)*180*1.0/m;
		int flag=0;
		for(int i=0;i<=360/alg1;i++){
			flag=0;
			for(int j=0;j<=360/alg2;j++){
				if(i*alg1+j*alg2==360)flag=1;
				if(flag==1)break;
			}
			if(flag==1)break;
		}
		if(flag==1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}