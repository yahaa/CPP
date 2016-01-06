#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,m;
		cin>>a>>b>>m;
		int x,y;
		int can=0;
		for(x=m/a;x>=0;x--){
			if((m-a*x)%b==0){
				can=1;
				break;
			}
		}

			if(can)cout<<x<<" "<<(m-a*x)/b<<endl;
			else cout<<"Impossible"<<endl;
	}
}