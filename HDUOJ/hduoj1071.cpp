#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int t;
	cin>>t;
	double x1,y1,x2,y2,x3,y3;
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		double h=x1;
		double k=y1;
		double a=(y2-k)/pow(x2-h,2);
		double b=(y3-y2)/(x3-x2);
		double c=y3-b*x3;
		double ans=(a*pow(x3,3)/3-(2*a*h+b)*x3*x3/2+(a*h*h+k-c)*x3)-(a*pow(x2,3)/3-(2*a*h+b)*x2*x2/2+(a*h*h+k-c)*x2);
		printf("%.2lf\n",ans);
	}
	return 0;
}