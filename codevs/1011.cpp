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
#include <fstream>
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
int ans;

void select(int i){
	if(i==1)return;
	for(int n=i/2;n>=1;n--){
		ans++;
		select(n);
	}
}

int main(){
	int n;
	while(cin>>n){
		ans=0;
		for(int i=n/2;i>=1;i--){
			ans++;
			select(i);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}
