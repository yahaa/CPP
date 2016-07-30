/*************************************************************************
	> File Name: hdu2896.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年07月30日 星期六 14时52分08秒
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
vector<int>ans;
struct node{
	int no;
	node *fail;
	node *next[maxn];
	node(){
		no=0;
		fail=NULL;
		MS(next,0);
	}
};

class AC{
private:
	node *root;
	void delete_tree(node *r){
		for(int i=0;i<maxn;i++){
			if(r->next[i])delete_tree(r->next[i]);
		}
		delete r;
	}

public:
	AC(){
		root=new node;
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
					else{
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


	void insert(string s,int no){
		node *loca=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-31;
			if(!loca->next[index])loca->next[index]=new node;
			loca=loca->next[index];
		}
		loca->no=no;
	}

	bool query(string s){
		ans.clear();
		queue<node*>back;
		node *p=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-31;
			while(!p->next[index]&&p!=root)p=p->fail;
			p=p->next[index];
			p=(!p)?root:p;
			node *temp=p;
			while(temp!=root){
				if(temp->no>0){
					ans.push_back(temp->no);
					temp->no=-temp->no;
					back.push(temp);
				}
				else break;
				temp=temp->fail;
			}
		}

		while(!back.empty()){
			node *tt=back.front();
			back.pop();
			tt->no=-tt->no;
		}
		return ans.size()>0;
	}

	void del(){
		delete_tree(root);
	}

};

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	int n,m;
	char ch[10005];

	while(cin>>n){
		AC a;
		int total=0;
		string s;
		for(int i=1;i<=n;i++){
			scanf("%s",ch);
			s=ch;
			a.insert(s,i);
		}
		a.builFail();
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%s",ch);
			s=ch;
			if(a.query(s)){
				printf("web %d:",i);
				total++;
				sort(ans.begin(),ans.end());
				for(int j=0;j<ans.size();j++)printf(" %d",ans[j]);
				printf("\n");
			}
		}
		printf("total: %d\n",total);
		a.del();

	}

	return 0;
}

