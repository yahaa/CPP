/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
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
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
int a[8]={5,-12,-3,-4,-10,7,-50,11};

int  binary(int l,int r){
	int mid=(l+r)/2;
	if(mid==a[mid])return mid;
	else if(mid<a[mid])return binary(l,mid);
	else return binary(mid+1,r);
}

void max_min(int & max_,int & min_,int n){
	if(n==1){
		min_=max_=a[n];
		return;
	}
	max_=a[0];
	min_=a[1];
	for(int i=2;i<n-1;i+=2){
		if(a[i]>a[i+1]){
			max_=max(max_,a[i]);
			min_=min(min_,a[i+1]);
		}
		else {
			max_=max(max_,a[i+1]);
			min_=min(min_,a[i]);
		}
	}

}

int main(){
	
	sort(a,a+8);
	cout<<binary(0,8)<<endl;
	return 0;
}

