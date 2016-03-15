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
	int n;
	string s;
	int t=1;
	while(cin>>n&&n){
		cin>>s;
		cout<<"Test case #"<<t++<<endl;
		for(int i=1;i<s.length();i++){
			string ts=s.substr(0,i+1);
			int p=getnumber(ts);
			if(p>1)cout<<i+1<<" "<<p<<endl;
		}
	}
	return 0;
}