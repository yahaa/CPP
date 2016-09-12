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
	int n,m,a;
	while(cin>>n>>m>>a){
		ll ans=0;
		if(n<=a||m<=a){
			int len=max(n,m);
			ans+=(len%a==0)?len/a:len/a+1;
		}
		else {
			ans=((n%a==0)?n/a:n/a+1)*((m%a==0)?m/a:m/a+1);
		}
		cout<<ans<<endl;
	}

	return 0;
}
