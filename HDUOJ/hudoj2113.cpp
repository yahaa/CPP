#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int sum;
	bool flag=0;
	while(cin>>s){
		sum=0;
		for(int i=0;i<s.length();i++){
			if((s[i]-'0')%2==0)sum+=s[i]-'0';
		}
		if(flag==0){
		    cout<<sum<<endl;
		    flag=1;
		}
		else cout<<endl<<sum<<endl;
	}
	return 0;
}