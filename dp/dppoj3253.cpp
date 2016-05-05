/*************************************************************************
	> File Name: dppoj3253.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年05月05日 星期四 20时42分33秒
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
using namespace std;
const int maxn=20000;

int main(){
	int n;
	while(cin>>n){
		priority_queue<int,vector<int> ,greater<int> >qu;
		int t;
		for(int i=0;i<n;i++){
			cin>>t;
			qu.push(t);
		}
		long long ans=0;
		while(qu.size()>1){
			int l1=qu.top();
			qu.pop();
			int l2=qu.top();
			qu.pop();
			ans+=l1+l2;
			qu.push(l1+l2);
		}
		cout<<ans<<endl;
	}
	return 0;
}

