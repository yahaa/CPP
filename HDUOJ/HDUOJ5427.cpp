#include <iostream>   //water
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=101;
struct people{
	string name;
	string brith;
};

bool cmp(people a,people b){
	return a.brith>b.brith;
}
int main(){
	int t;
	cin>>t;
	people p[maxn];
	string s;
	while(t--){
		int n;
		cin>>n;
		getchar();
		for(int i=0;i<n;i++){
			getline(cin,s,'\n');
			p[i].name=s.substr(0,s.length()-5);
			p[i].brith=s.substr(s.length()-4);
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++)cout<<p[i].name<<endl;
	}
return 0;
}
