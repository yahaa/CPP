/*************************************************************************
	> File Name: test.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年04月28日 星期四 17时31分16秒
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
	cin>>t;
	stack<int>sta;
	while(t--){
		int a; 
		cin>>a;
		sta.push(a);
		
	}
	while(!sta.empty()){
		cout<<sta.top();
		sta.pop();
	}
	return 0;
}
