/*************************************************************************
	> File Name: binarySearch_poj1064.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月02日 星期一 22时43分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
using namespace std;
double L[10005];
int n,k;

bool C(double len){
	int t=0;
	for(int i=0;i<n;i++){
		t+=(int)(L[i]/len);
	}
	return t>=k;
}
int main(){
	while(cin>>n>>k){
		double ll=0,lr=0;
		for(int i=0;i<n;i++){
			scanf("%lf",&L[i]);
			lr=max(lr,L[i]);
		}
		for(int i=0;i<100;i++){
			double mid=(ll+lr)/2;
			if(C(mid))ll=mid;
			else lr=mid;
		}
		printf("%.2f\n",floor(lr*100)/100);
	}
	return 0;
}

