#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=26;
struct node{
	bool isWord;
	node *next[maxn];
	node(){
		memset(next,NULL,sizeof(next));
	}
};

class Trie{
public:
	node *root;
	Trie(){
		root=new node;
	}

	void insert(string s){
		node *loca=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-'a';
			if(!loca->next[index])
				loca->next[index]=new node;
			loca=loca->next[index];
		}
		loca->isWord=true;
	}

	bool search(string s){
		node*loca=root;
		for(int i=0;i<s.length();i++){
			int index=s[i]-'a';
			if(!loca->next[index])return false;
			loca=loca->next[index];
		}
		return true;
	}

	void del(){
		delete_tree(root);
	}

	void delete_tree(node*r){
		for(int i=0;i<maxn;i++){
			if(r->next[i])
				delete_tree(r->next[i]);
		}
		delete r;
	}

};

int main(){
	map<string,string>mp;
	string s;
	cin>>s
	string en,fo;
	char s1[50],s2[50];
	Trie a;
	while(s=="START"){
		scanf("%s",s1);
		en=s1;
		if(en=="END")break;
		scanf("%s",s2);
		map[fo]=en;
		a.insert(fo);
	}

	cin>>s;
	char ts[3005];
	while(s=="START"){
		gets(ts);
		s=ts;
		for(int i=0;i<s.length();i++){
			for(int j=i+1;j<s.length();j++){
				if(!isAlphabet(s[j]))........
			}
		}
	}


}