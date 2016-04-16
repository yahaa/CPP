#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using  namespace std;
int main(){
	map<string,int>a;
	int n;
	string s;
	while(cin>>n){
		a.clear();
		while(n--){
			cin>>s;
			a[s]++;
		}
		cout<<a.size()<<endl;
		for(map<string,int>::iterator it=a.begin();it!=a.end();++it){
			cout<<it->first<<endl;
		}

	}
}