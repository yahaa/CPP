#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;

int exGcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    int r=exGcd(b,a%b,x,y);
    int t=x;x=y;y=t-a/b*y;
    return r;
}

int inv(int a,int mi){
	int x,y;
	exGcd(a,mi,x,y);
	return x;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int p,e,i,d;
		int tt=1;
		int m=23*28*33;
		while(cin>>p>>e>>i>>d){
			if(p==-1&&e==-1&&i==-1&&d==-1)break;
			
			int m1=m/23;
			int m2=m/28;
			int m3=m/33;
			int t1=inv(m1,23);
			int t2=inv(m2,28);
			int t3=inv(m3,33);
			int ans=(p*t1*m1+e*t2*m2+i*t3*m3)%m;
			ans-=d;
			if(ans<=0)ans+=m;
			printf("Case %d: the next triple peak occurs in %d days.\n",tt++,ans);
		}
	}
	return 0;
}