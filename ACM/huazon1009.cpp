/*************************************************************************
	> File Name: huazon1009.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月15日 星期日 10时39分55秒
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

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		stack<string>n1,n2;
		string s;
		int po=1;
		while(cin>>s&&s!="END"){
			if(po==1){
				if(n1.empty()||n1.top()!=s){
					n1.push(s);
					po=1;
				}
				else {
					n2.push(s);
					po=2;
				}
			}
			else {
				if(n2.empty()||n2.top()!=s){
					n2.push(s);
					po=2;
				}
				else {
					n1.push(s);
					po=1;
				}
			}
		}
		cout<<n1.size()*n2.size()<<endl;
	}

	return 0;
}

