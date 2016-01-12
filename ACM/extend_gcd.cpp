#include<iostream>
using namespace std;
int exGcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int r=exGcd(b,a%b,x,y);
    int t=x;x=y;y=t-a/b*y;
    return r;
}

int GCD(int a,int b){
	if(b==0)return a;
	else return GCD(b,a%b);
}
int main(){
	int a,b,c;
	while(cin>>a>>b>>c){
		int x0,y0;
		int d=exGcd(a,b,x0,y0);
		cout<<d<<" "<<x0*c/d<<" "<<y0*c/d<<endl;
		cout<<GCD(a,b)<<endl;
		(a==0?a=-1:a=100);
		cout<<a<<endl;
	}
}