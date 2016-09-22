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
	cin>>s;
	bool ok=false;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			s[i]='d';
			ok=true;
			break;
		}
	}
	
	if(ok){
		for(int i=0;i<s.length();i++)
			if(s[i]!='d')cout<<s[i];
	}
	else 
		for(int i=0;i<s.length()-1;i++)cout<<s[i];
	cout<<endl;

	return 0;
}
