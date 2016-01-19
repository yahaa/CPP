#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;
int main(){
	
	string in,out;
	int n;
	vector<string>ans;
	while(cin>>n){
		ans.clear();
		stack<char>s1;
		in.clear();
		out.clear();
		cin>>in>>out;
		queue<char>quin,quout;
		for(int i=0;i<in.length();i++)quin.push(in[i]);
		for(int i=0;i<out.length();i++)quout.push(out[i]);
			
		while(!quin.empty()){
			s1.push(quin.front());
			ans.push_back("in");
			quin.pop();
			if(s1.top()==quout.front()){
				s1.pop();
				ans.push_back("out");
				quout.pop();
			}
			while(!s1.empty()&&quout.front()==s1.top()){
				s1.pop();
				ans.push_back("out");
				quout.pop();
			}
		}
		if(quin.empty()&&quout.empty()){
			cout<<"Yes."<<endl;
			for(vector<string>::iterator it=ans.begin();it!=ans.end();++it)cout<<*it<<endl;
		}
		else cout<<"No."<<endl;
		cout<<"FINISH"<<endl;

	}
	return 0;
}