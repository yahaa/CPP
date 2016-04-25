#include <iostream>
#include <string>
using namespace std;
int getnumber(string s){
	int count=0;
	for(int i=1;i<=s.length()/2;i++){
		string ts=s.substr(0,i);
		count=0;
		int j;
		for(j=0;j<s.length();j++){
			string tss=s.substr(j,i);
			if(tss==ts){
				count++;
				j+=i-1;
			}
			else {
				count=0;
				break;
			}
		}
		if(j==s.length())break;
	}
	return count;
}
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		
	}
	return 0;
}