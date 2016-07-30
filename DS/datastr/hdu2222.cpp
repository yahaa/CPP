/*************************************************************************
	> File Name: hdu2222.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月30日 星期六 09时55分02秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;
const int maxn=26;

struct node{
	int count;
	node *fail;
	node *next[maxn];
	node(){
		count=0;
		fail=NULL;
		MS(next,0);
	}
};

class AC{
private:
	node *root;
	void delete_tree(node*r){
		for(int i=0;i<maxn;i++){
			if(r->next[i])delete_tree(r->next[i]);
		}
		delete r;
	}

	void builFail(){
		queue<node*>qu;
		root->fail=NULL;
		qu.push(root);
		while(!qu.empty()){
			node *temp=qu.front();
			qu.pop();
			node *p=NULL;
			for(int i=0;i<maxn;i++){
				if(temp->next[i]){
					if(temp==root)temp->next[i]->fail=root;
					else {
						p=temp->fail;
						while(p){
							if(p->next[i]){
								temp->next[i]->fail=p->next[i];
								break;
							}
							p=p->fail;
						}
						if(!p)temp->next[i]->fail=root;
					}
					qu.push(temp->next[i]);
				}
			}
		}
	}


public:
	AC(){
		root=new node;
	}

	void insert(string s){
		node *loca=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-'a';
			if(!loca->next[index])loca->next[index]=new node;
			loca=loca->next[index];
		}
		loca->count++;
	}

	int query(string s){
		builFail();
		int ans=0;
		node *p=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-'a';
			while(p->next[index]==NULL&&p!=root)p=p->fail;
			p=p->next[index];
			p=(p==NULL)?root:p;
			node*temp=p;
			while(temp!=root){
				if(temp->count>=0){
					ans+=temp->count;
					//temp->count=-1;
				}
				else break;
				temp=temp->fail;
			}
		}
		return ans;
	}

	void del(){
		delete_tree(root);
	}
	

};

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int t,n;
	string s;
	scanf("%d",&t);
	char ch[1000005];
	while(t--){
		AC a;
		scanf("%d",&n);
		while(n--){
			scanf("%s",ch);
			s=ch;
			a.insert(s);
		}
		scanf("%s",ch);
		s=ch;
		int ans=a.query(s);
		printf("%d\n",ans);
		a.del();
	}
	
	return 0;
}

