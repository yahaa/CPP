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
	string s;
	int n;
	cin>>n>>s;
	int sum1=0,sum2=0;
	bool ok=true;
	for(int i=0;i<n/2;i++){
		int t=s[i]-'0';
		if(t==4||t==7){
			sum1+=t;
		}
		else {
			ok=false;
			break;
		}
	}

	for(int i=n/2;i<n;i++){
		int t=s[i]-'0';
		if(t==4||t==7){
			sum2+=t;
		}
		else {
			ok=false;
			break;
		}
	}
	
	if(sum1!=sum2)ok=false;
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
