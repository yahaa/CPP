#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=26;
struct node{
	bool isWord;
	node *next[maxn];
	node(){
		isWord=false;
		for(int i=0;i<maxn;i++){
			next[i]=NULL;
		}
	}
};

class Trie{
	public:
		node *root;
		Trie(){
			root=new node();
		}

		void del(){
			delete_trie(root);
		}

		void delete_trie(node*r){
			for(int i=0;i<maxn;i++){
				if(r->next[i]){
					delete_trie(r->next[i]);
				}
			}
			delete r;
		}

		void insert(string s){
			node *locat=root;
			for(int i=0;i<s.length();i++){
				int index=s[i]-'a';
				if(!locat->next[index])
					locat->next[index]=new node;
				locat=locat->next[index];
			}
			locat->isWord=true;
		}

		bool search(string s){
			node *locat=root;
			for(int i=0;i<s.length();i++){
				int index=s[i]-'a';
				if(!locat->next[index])return false;
				locat=locat->next[index];
			}
			return locat->isWord;
		}

};


int main(){
	Trie a;
	int i=0;
	string s[50005];
	char ch[50];
	while(scanf("%s",ch)!=EOF){
		s[i]=ch;
		a.insert(s[i]);
		i++;
	}
	
	int count=i;
	for(i=0;i<count;i++){
		int len=s[i].length();
		for(int j=1;j<=len-2;j++){
			string s1=s[i].substr(0,j);
			string s2=s[i].substr(j,len-j);
			if(a.search(s1)&&a.search(s2)){
				cout<<s[i]<<endl;
				break;
			}
		}
	}
	a.del();
	return 0;

}