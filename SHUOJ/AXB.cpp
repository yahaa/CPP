#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=105;
char ch[maxn];
stack<char>a;
void init(){
	while(!a.empty())a.pop();
}
int main(){
	int t;
	cin>>t;
	
	while(t--){
		init();
		int n;
		cin>>n;
		int ans=0;
		for(int i=0;i<n;i++)cin>>ch[i];
		for(int i=0;i<n;i++){
			if(ch[i]==')'){
				if(a.empty()){
					a.push('(');
					ans++;
				}
				else if(a.top()=='('){
					a.pop();
				}
				else {
					a.push('(');
					ans++;
				}
			}
			else {
				a.push('(');
			}
		}
		ans+=a.size()/2;
		cout<<ans<<endl;
	}
	return 0;
}