#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
string s;
while(getline(cin,s)){
	int ans;
	stringstream ss(s);
		int x;
	if(s[s.length()-1]=='k'){
		
		int a;
		while(ss>>x)a=x;
		if(a==7||(a>=1&&a<=4))ans=52;
		else ans=53;
	}

	else {
		int a;
		while(ss>>x)a=x;
		if(a==31)ans=7;
		else if(a==30)ans=11;
		else ans=12;
	}
	cout<<ans<<endl;
}
}