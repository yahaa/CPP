#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
const double PI=1.570796;
const double n=108.0;
const double w1=14.7;
const double w2=15.7;

int main(){
	double r=10e18-1;
	double sing=0.39795*cos(0.98653*(n-173));
	double cosg=sqrt(1-sing*sing);
	double ta,tb;
	for(double a=-PI;a<=PI;a+=0.0001){
		for(double b=-PI;b<=PI;b+=0.0001){
			double sinh2=sin(b)*sing+cos(b)*cosg*cos(300-15*w2-a);
			double sinh1=sin(b)*sing+cos(b)*cosg*cos(300-15*w1-a);
			double cosh2=sqrt(1-sinh2*sinh2);
			double cosh1=sqrt(1-sinh1*sinh1);
			double cosr1=(sinh1*sin(b)-sing)/(cosh1*cos(b));
			double cosr2=(sinh2*sin(b)-sing)/(cosh2*cos(b));
			double tQ=acos(cosr1)-acos(cosr2);
			double f=(sinh2*cosh1)/(cosh2*sinh1);
			double tr=sqrt(0.53*(f-0.5963)*(f-0.5963)+0.47*(tQ-0.1235));
			if(tr<r){
				ta=a;
				tb=b;
				r=tr;
				printf("%lf %lf %lf\n",ta,tb,r);
			}
		}
	}
	cout<<"b="<<tb<<" a="<<ta<<" r="<<r<<endl;
	return 0;
}