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
map<char,int>mp;
int main(){
	string s;
	mp['a']=1;
	mp['e']=1;
	mp['i']=1;
	mp['u']=1;
	mp['y']=1;
	mp['o']=1;
	while(cin>>s){
		for(int i=0;i<s.length();i++){
			if(isupper(s[i]))s[i]=tolower(s[i]);
			if(mp[s[i]])continue;
			else cout<<"."<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
