#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <malloc.h>
#include <stdio.h>
using namespace std;
const int maxn=26;
struct node{
	int count;
	node *next[maxn];
	node(){
		count=0;
		for(int i=0;i<maxn;i++)next[i]=NULL;
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
			if(!loca->next[index]){
				loca->next[index]=new node;
			}
			loca->next[index]->count++;
			loca=loca->next[index];
		}
	}

	int  search(string s){
		node *loca=root;
		bool f=true;
		for(int i=0;i<s.length();i++){
			int index=s[i]-'a';
			if(!loca->next[index]){
				f=false;
				break;
			}
			loca=loca->next[index];
		}
		if(f)return loca->count;
		else return 0;
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

};

int main(){
	string s;
	char ch[15];
	Trie a;
	while(gets(ch),*ch){
		s=ch;
		a.insert(s);
	}

	while(scanf("%s",ch)!=EOF){
		s=ch;
		printf("%d\n",a.search(s));
	}
	a.del();
	return 0;
}