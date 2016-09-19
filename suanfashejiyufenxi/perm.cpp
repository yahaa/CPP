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


inline void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}

void perm(int list[],int k,int m){
	if(k==m){
		for(int i=0;i<m;i++)cout<<list[i]<<" ";
		cout<<endl;
	}
	else
		for(int i=k;i<m;i++){
			swap(list[k],list[i]);
			perm(list,k+1,m);
			swap(list[k],list[i]);
		}
}

int main(){
	int a[3]={1,2,3};
	// do{
	// 	for(int i=0;i<7;i++)cout<<a[i]<<" ";
	// 	cout<<endl;
	// }while(next_permutation(a,a+7));
	perm(a,0,3);
	return 0;
}
