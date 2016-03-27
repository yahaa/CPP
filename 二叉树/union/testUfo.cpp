#include <iostream>
#include <algorithm>
#include "UFO.h"
using namespace std;
const int maxn=1000;
int preant[maxn];
int find(int x){
	int r=x;
	while(preant[r]!=r)r=preant[r];
	int tr=x,tp;
	while(preant[tr]!=r){
		tp=preant[tr];
		preant[tr]=r;
		tr=tp;
	}
	return r;
}

void join(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		preant[y]=x;
	}
}
void init(){
	for(int i=0;i<maxn;i++)preant[i]=i;
}
int main(){
	int t[17];
	for(int i=0;i<17;i++)t[i]=i;
	UFO<int>s(t,17),d(t,17),f(t,17);
	int a,b;
	for(int i=1;i<=16;i++){
		cin>>a>>b;
		s.unions1(a,b);
		d.unions2(a,b);
		f.unions3(a,b);
	}
	cout<<"Test unions1"<<endl;
	s.print();
	cout<<endl;
	cout<<"Test unions2"<<endl;
	
	d.print();
	cout<<endl;
	cout<<"Test unions3"<<endl;
	f.print();
}
