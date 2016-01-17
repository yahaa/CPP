#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		for(int i=0;i<s.length();i++)printf("%c",s[i]-7);
			cout<<endl;
	}
	return 0;
}