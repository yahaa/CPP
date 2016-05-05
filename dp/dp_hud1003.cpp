/*************************************************************************
	> File Name: dp_hud1003.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 11时02分03秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>
#include<cstring>
#include<set>
#include<bitset>
using namespace std;
int main(){
	int t;
	int tt=1;
	cin>>t;
	int temp,maxs,now;
	int n;
	int m=t;
	while(t--){
		cin>>n>>temp;
		maxs=now=temp;
		int s,e,ts;
		s=e=ts=1;
		for(int i=2;i<=n;i++){
			cin>>temp;
			if(now<0){
				now=temp;
				ts=i;
			}
			else now+=temp;
			if(now>maxs){
				maxs=now;
				s=ts;
				e=i;
			}
		}
		printf("Case %d:\n%d %d %d\n",tt,maxs,s,e);
		if(tt++<m)cout<<endl;
	}
	return 0;
}

