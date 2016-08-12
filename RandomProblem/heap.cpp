
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
	int n;
	priority_queue<int,vector<int>,greater<int> >qu;
	while(cin>>n){
		while(!qu.empty())qu.pop();
		int t;
		for(int i=0;i<n;i++){
			cin>>t;
			qu.push(t);
		}
		int ans=0;
		while(qu.size()!=1){
			int t1=qu.top();
			qu.pop();
			int t2=qu.top();
			qu.pop();
			ans+=t1+t2;
			qu.push(t1+t2);
		}
		cout<<ans<<endl;
		
	}
	

	return 0;
}

