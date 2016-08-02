/*************************************************************************
	> File Name: baiduc.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月14日 星期六 13时41分38秒
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
#define MS(a,x) memset(a,x,sozeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
map<string,int>mp;
int main(){
	string op,s;
	int n;
	cin>>n;
	getchar();
	while(n--){
		getline(cin,op,' ');
		getline(cin,s);
		if(op=="insert"){
			for(int i=s.length(),j=1;i>=1;i--,j++){
				mp[s.substr(0,i)]+=j;
			}
		}
		if(op=="search"){
			
			if(mp[s])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		if(op=="delete"){
			mp[s]=0;
		}
	}
	

	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);


	return 0;
}

