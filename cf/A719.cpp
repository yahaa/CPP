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

int main(){
	int n,a,b;
	cin>>n>>a;
	int tp=0;
	for(int i=1;i<n;i++){
		cin>>b;
		tp=b-a;
		a=b;
	}
	if(n==1){
		if(a==0)cout<<"UP"<<endl;
		else if(a==15)cout<<"DOWN"<<endl;
		else cout<<-1<<endl;
	}
	else{
		if(a==0)cout<<"UP"<<endl;
		else if(a==15)cout<<"DOWN"<<endl;
		else {
			if(tp>0)cout<<"UP"<<endl;
			else cout<<"DOWN"<<endl;
		}
	}
	
	return 0;
}
