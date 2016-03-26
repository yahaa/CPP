#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// typedef long long ll;
// const int maxn=10000000;
// bool is_prime[maxn];
// int solve1(int n){
// 	for(int i=0;i<=n;i++)is_prime[i]=true;
// 	int ans=0;
// 	for(int i=2;i<=n;i++){
// 		if(is_prime[i]){
// 			ans++;
// 			for(int j=i*2;j<=n;j+=i)is_prime[j]=false;
// 		}
// 	}
// 	return ans;
// }



int main(){
	int n;
	cin>>n;
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(n--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if(x1==x2==x3==x4||y1==y2==y3==y4)cout<<"NO"<<endl;
		else {
			double t1=abs(y2-y1);
			double t2=abs(x2-x1);
			double t3=abs(y4-y3);
			double t4=abs(x4-x3);
		
			if(t1/t2==t3/t4&&t2*t4!=0){
				double t=-t1/t2*x1+y1;
				if(y3==t1/t2*x3+t)cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}



