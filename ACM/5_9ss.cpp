/*************************************************************************
	> File Name: 5_9ss.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月09日 星期一 18时22分54秒
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
// char ans[100000];
// int len;

// void dfs(string s,int i){
// 	if(s.length()==0)return;
// 	int t1=0,t0=0;
// 	for(int j=0;j<s.length();j++){
// 		if(s[j]=='0')t0++;
// 		if(s[j]=='1')t1++;
// 	}
// 	if(t1>0&&t0>0)ans[i]='F';
// 	else if(t1>0&&t0==0)ans[i]='I';
// 	else if(t1==0&&t0>0)ans[i]='B';
// 	len++;
// 	dfs(s.substr(0,s.length()/2),i*2);
// 	dfs(s.substr(s.length()/2,s.length()/2),i*2+1);
// }

// void prin(int i){
// 	if(i>len)return;
// 	prin(i*2);
// 	prin(i*2+1);
// 	cout<<ans[i];
// }
// int main(){
// 	//freopen("xxxxin.txt","r",stdin);
// 	//freopen("xxxxout.txt","w",stdout);

// 	int n;
// 	string s;
// 	while(cin>>n){
// 		len=0;
// 		cin>>s;
// 		dfs(s,1);
// 		prin(1);
// 		cout<<endl;
// 	}
	
// 	return 0;
// }

// int main(){
// 	int n;
// 	int a[250];
// 	while(cin>>n){
// 		memset(a,0,sizeof(a));
// 		priority_queue<int,vector<int>,greater<int> >qu;
// 		int tt;
// 		for(int i=0;i<n;i++){
// 			cin>>tt;
// 			qu.push(tt);
// 		}
// 		a[101]=qu.top();
// 		qu.pop();
// 		int left=101,right=101;
// 		bool f=true;
// 		while(f&&qu.size()>0){
// 			int t=qu.top();
// 			qu.pop();
// 			if(t<a[right])a[++right]=t;
// 			else if(t<a[left])a[--left]=t;
// 			else f=0;
// 		}
// 		cout<<qu.size()<<endl;
// 	}
// }
struct job
{
	int j;
	int p;
};
int pri[10];
int main(){
	int t;
	cin>>t;
	int a[105];
	while(t--){
		memset(pri,0,sizeof(pri));
		queue<job>qu;
		int n,pos;
		cin>>n>>pos;
		int p;
		for(int i=0;i<n;i++){
			cin>>p;
			a[i]=p;
			pri[p]++;
		}

		for(int i=n-1;i>=0;i--){
			job tj;
			tj.j=i;
			tj.p=a[i];
			qu.push(tj);
		}

		int ans=0;
		do{
			job tp;
			tp.j=qu.front().j;
			tp.p=qu.front().p;
			qu.pop();
			if(tp.p==9){
				pri[tp.p]--;
				ans++;
				pos--;
			}
			else{
				int sum=0;
				for(int i=9;i>tp.p;i--){
					sum+=pri[i];
				}
				if(sum>0){
					qu.push(tp);
					if(pos==0)pos=qu.size()+1;
					else pos--;
				}
				else {
					pri[tp.p]--;
					ans++;
					pos--;
				}
			}
			
		}while(pos>0&&!qu.empty());
		cout<<ans<<endl;
	}
	return 0;
}