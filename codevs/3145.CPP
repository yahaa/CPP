// made by ggeh
#include <iostream>
#include <queue>
using namespace std;
int ans;
queue<string>que;

void move(int top,int end,char from,char to,char left){
	if(top==end){ans++;
		string s="";
		if(top==10)s+="10";
		else s+=char('0'+top);
		s+=" from ";s+=from;s+=" to ";s+=to;
		que.push(s);
		return;
	}
	move(top,end-1,from,left,to);
	move(end,end,from,to,left);
	move(top,end-1,left,to,from);
}

int main(){
	int n;
	while(cin>>n){
		ans=0;
		move(1,n,'A','C','B');
		cout<<ans<<endl;
		while(!que.empty()){
			cout<<que.front()<<endl;
			que.pop();
		}
	}
	return 0;
}