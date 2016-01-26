#include <iostream>     //这题的核心还是二分查找的思想　
#include <cstdio>       //但是不同的是这题需要一些数学求导的知识
#include <cmath>
#include <algorithm>
using namespace std;
double f1(double x,double y){
	return 6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x;
}

double f2(double x){    
	return 42*pow(x,6.0)+48*pow(x,5.0)+21*pow(x,2)+10*x;
}

double y,l,r,m;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>y;
		r=100;
		l=0;
		while(r-l>1e-6){   //解题思路是　先对 F(x) = 6 * x^7+8*x^6+7*x^3+5*x^2-y*x (0 <= x <=100)求一次导
			m=(r+l)/2;     //然后继续求二次导　，通过观察二次导的规律可知，一阶导函数为增函数，
			if(f2(m)>y)r=m;   //所以问题的关键变成求出使得一阶导为０的极值点，最后把极值点代入原函数就可以得出函数在
			else l=m;         //(0 <= x <=100) 的最小值
		}
		printf("%.4lf\n",f1((l+r)/2,y));
	}
	return 0;
}