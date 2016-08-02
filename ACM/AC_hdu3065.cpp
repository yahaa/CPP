/*************************************************************************
	> File Name: hdu3065.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月30日 星期六 16时37分33秒
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

const int maxn=130;
map<string,int>mp;

struct node{
	int count;
	string s;
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
			int index=s[i]-31;
			if(!loca->next[index])loca->next[index]=new node;
			loca=loca->next[index];
		}
		loca->count++;
		loca->s=s;
	}

	void query(string s){
		builFail();
		mp.clear();
		node *p=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-31;
			while(p->next[index]==NULL&&p!=root)p=p->fail;
			p=p->next[index];
			p=(p==NULL)?root:p;
			node*temp=p;
			while(temp!=root){
				if(temp->count>0){
					mp[temp->s]=mp[temp->s]+temp->count;
				}
				else break;
				temp=temp->fail;
			}
		}
	}

	void del(){
		delete_tree(root);
	}
	

};

char wo[55];
char ch[2000005];
vector<string>ins;

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n;
	string s;
	while(scanf("%d",&n)!=EOF){
		ins.clear();
		AC a;
		for(int i=0;i<n;i++){
			scanf("%s",wo);
			s=wo;
			ins.push_back(s);
			a.insert(s);
		}
		getchar();
		getline(cin,s);
		a.query(s);
		for(int i=0;i<n;i++){
			if(mp[ins[i]])cout<<ins[i]<<": "<<mp[ins[i]]<<endl;
		}

		a.del();
	}


	return 0;
}

