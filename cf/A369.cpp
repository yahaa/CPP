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
	int n,dish[3],a,b,t;
	cin>>n>>a>>b;
	dish[1]=a;
	dish[2]=b;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t==1){
			if(dish[1])dish[1]--;
			else ans++;
		}
		else {
			if(dish[1]||dish[2]){
				if(dish[2])dish[2]--;
				else if(dish[1])dish[1]--;
			}
			else ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}
