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
	int n,t;
	string s;
	cin>>n>>t>>s;
	int index=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='.'){
			index=i;
			break;
		}
	}
	if(index==-1)return 0;

	int bi=-1;
	for(int i=index+1;i<n;i++){
		if(s[i]>='5'&&t-->0){
			bi=i-1;
			s[bi]++;
			break;
		}
	}
	if(bi==-1)cout<<s;
	else if(s[bi]=='.'){
		int in=1;
		for(int i=bi-1;i>=0;i--){
			int tv=s[i]-'0';
			s[i]=(tv+in)%10+'0';
			in=(tv+in)/10;
			if(in==0)break;
		}
		if(in)cout<<in;
		for(int i=0;i<=bi-1;i++)cout<<s[i];
	}
	else {
		for(int i=bi;i>index;i--){
			if(t>0){
				if(s[i]<'5'){
					bi=i;
					break;
				}
				else {
					t--;
					bi=i-1;
					s[i-1]++;
				}
			}
			else break;
		}
		if(bi==index){
			int in=1;
			for(int i=index-1;i>=0;i--){
				int tv=s[i]-'0';
				s[i]=(tv+in)%10+'0';
				in=(tv+in)/10;
				if(in==0)break;
			}
			if(in)cout<<in;
			for(int i=0;i<=index-1;i++)cout<<s[i];
		}
		else 
			for(int i=0;i<=bi;i++)cout<<s[i];
	}

	cout<<endl;
	return 0;
}
