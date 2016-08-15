#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<char,int>mp;
int main(){
	string a,b;
	for(int i=0;i<=9;i++){
		char t='0'+i;
		mp[t]=i;
	}
	for(int i=0;i<=6;i++){
		char t='a'+i;
		mp[t]=10+i;
	}
	while(cin>>a>>b){
		for(int i=0;i<a.length();i++){
			if(isalpha(a[i]))a[i]=tolower(a[i]);
		}
		for(int i=0;i<b.length();i++){
			if(isalpha(b[i]))b[i]=tolower(b[i]);
		}
		ll suma=0,sumb=0;
		for(int i=a.length()-1;i>=0;i--){
			sum*=
		}


	}
	return 0;
}