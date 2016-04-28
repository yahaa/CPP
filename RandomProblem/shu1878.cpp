/*************************************************************************
	> File Name: shu1878.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年04月28日 星期四 19时14分25秒
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
int a[100000];
int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int tt;
		while(m--){
			scanf("%d",&tt);
			int ans=binary_search(a,a+n,tt);
			if(ans)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
	}
	return 0;
}
