#include <iostream>
#include <cmath>       //二分法找答案　　　时间复杂度　　　　O(logN)
#include <algorithm>
#include <cstdio>
using namespace std;
double l,r,m,y;
double f(double x){
	return 8.0*pow(x,4.0)+7.0*pow(x,3.0)+2.0*pow(x,2.0)+3*x+6.0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>y;
		if(y>=f(0)&&y<=f(100)){
			r=100;
			l=0;
			while(r-l>1e-6){   //利用精度误差来做循环条件
				m=(r+l)/2;
				double ans=f(m);
				if(ans>y)r=m;        //二分思想的体现
				else l=m;
			}
			printf("%.4lf\n",(l+r)/2);
		}
		else cout<<"No solution!"<<endl;
	}
	return 0;
}