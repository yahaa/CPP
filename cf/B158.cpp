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
int a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,t,sum=0,ans=0,le[4]={0,0,0,0};
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		t=a[i];
		if(t==4)ans++;
		else {
			bool ok=true;
			for(int i=t;i<=3;i++){
				if(le[i]){
					le[i]--;
					le[i-t]++;
					ok=false;
					break;
				}
			}
			if(ok){
				ans++;
				le[4-t]++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
