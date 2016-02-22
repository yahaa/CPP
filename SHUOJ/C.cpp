#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s;
	map<char,int>mp;
	for(int i=(int)'A';i<=(int)'z';i++){
		char chr=(char)i;
		if(chr>='A'&&chr<='C')mp[chr]=2;
		if(chr>='D'&&chr<='F')mp[chr]=3;
		if(chr>='G'&&chr<='I')mp[chr]=4;
		if(chr>='J'&&chr<='L')mp[chr]=5;
		mp['M']=6;
		mp['N']=6;
		mp['O']=6;
		if(chr>='P'&&chr<='S')mp[chr]=7;
		if(chr>='T'&&chr<='V')mp[chr]=8;
		if(chr>='W'&&chr<='Z')mp[chr]=9;
	}
	while(t--){
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(isalpha(s[i])){
				if(islower(s[i]))s[i]=(char)s[i]-'a'+'A';
			}
		}

		for(int i=0;i<s.size();i++){
			if(i==3){
				if(isalpha(s[i]))cout<<mp[s[i]]<<"-";
				else cout<<s[i]<<"-";
			}
			else{
				if(isalpha(s[i]))cout<<mp[s[i]];
				else cout<<s[i];
				}
			}
			cout<<endl;
	}
	return 0;
}