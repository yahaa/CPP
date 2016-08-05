#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
const double pi=3.1415926535898;
int main(){
	int t;
	cin>>t;
	double x1,y1,x2,y2,x3,y3;
	while(t--){
		cin>>x1>>y1;
		
		double r=sqrt(x1*x1+y1*y1);
		double a=asin(fabs(y1)/r);
		if(x1>=0&&y1>0)a=a;
		else if(x1<0&&y1>=0)a=pi-a;
		else if(x1>=0&&y1<0)a=2*pi-a;
		else if(x1<0&&y1<0)a=pi+a;
		double a1=a+2*pi/3;
		double a2=a+4*pi/3;
		x2=r*cos(a1);
		y2=r*sin(a1);
		x3=r*cos(a2);
		y3=r*sin(a2);
		if(fabs(y2-y1)>=0.0005){
			if(y2<y3)
				printf("%.3lf %.3lf %.3lf %.3lf\n",x2,y2,x3,y3);
			else 
				printf("%.3lf %.3lf %.3lf %.3lf\n",x3,y3,x2,y2);
		}
		else{
			if(fabs(x2-x3)>=0.0005){
				if(x2<x3)
					printf("%.3lf %.3lf %.3lf %.3lf\n",x2,y2,x3,y3);
				else 
					printf("%.3lf %.3lf %.3lf %.3lf\n",x3,y3,x2,y2);
			}
			else printf("%.3lf %.3lf %.3lf %.3lf\n",x3,y3,x3,y3);
				
		}
		
	}
	return 0;
}