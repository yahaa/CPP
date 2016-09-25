#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
//
void getNext(string x,int next[]){
	int m=x.length();
	next[0]=m;
	int j=0;
	while(j+1<m && x[j]==x[j+1])j++;
	next[1]=j;
	int k=1;
	for(int i=2;i<m;i++){
		int p=next[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)next[i]=L;
		else{
			j=max(0,p-i+1);
			while(i+j<m && x[i+j]==x[j])j++;
			next[i]=j;
			k=i;
		}
	}
}


void ekmp(string y,string x,int next[],int extend[]){
	int m=x.length();
	int n=y.length();
	getNext(x,next);
	int j=0;
	while(j<n && j<m && x[j]==y[j])j++;
	extend[0]=j;
	int k=0;
	for(int i=1;i<n;i++){
		int p=extend[k]+k-1;
		int L=next[i-k];
		if(i+L<p+1)extend[i]=L;
		else{
			j=max(0,p-i+1);
			while(i+j<n && j<m && y[i+j]==x[j])j++;
			extend[i]=j;
			k=i;
		}
	}
}

int main(){
	string y,x;
	int next[10000],extend[100000];
	while(cin>>y>>x){
		memset(next,0,sizeof(next));
		memset(extend,0,sizeof(extend));
		ekmp(y,x,next,extend);
		for(int i=0;i<y.length();i++){
			cout<<extend[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}