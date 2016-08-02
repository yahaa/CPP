#include <iostream>  
#include <cstdio>  
#include <string>  
#include <map>  
#include <set>  
using namespace std;
int main(){
	int n;
	string cn;
	string girl;
	while (cin>>n){
		map<string, int> a;
		while (n--){
			cin>>cn;
			getline(cin,girl);
			a[cn]++;
		}
		for (map<string, int> ::iterator it = a.begin(); it != a.end(); it++)
			printf("%s %d\n", (it->first).c_str(), it->second);
	}
	return 0;
}