#include <iostream>
// #include <algorithm>
// #include "UFO.h"
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
	// UFO<int>seta;
	// seta.unions(10,56);
	// cout<<seta.getRoot(56);

	cout<<"xxxxxxxxxxxxxxxxxxx"<<endl;
	cout<<sizeof(19999L)<<endl;
	cout<<sizeof(long long)<<endl;
	cout<<sizeof(int)<<endl;


}