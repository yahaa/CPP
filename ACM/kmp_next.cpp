#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
void getNext(const string &s,int *next){
	next[0]=0;
	int i=1;
	int k=0;
	while(i<s.length()){
		if(s[i]==s[k])next[i++]=++k;
		else {
			while(s[i]!=s[k]&&k!=0)k=next[k];
			next[i++]=k;
		}

	}
}
int main(){
	string s;
	cin>>s;
	int *next=new int[s.length()];
	getNext(s,next);
	for(int i=0;i<s.length();i++)cout<<next[i]<<" ";
}