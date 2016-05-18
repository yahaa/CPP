/*************************************************************************
	> File Name: char_9_5.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> QQ:1477765176 
	> Wechat:w1477765176 
	> Created Time: 2016年05月17日 星期二 22时18分11秒
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
#include "Link.h"
#include "XSB.h"
using namespace std;

void paoooo(int *a,int sizes){
	for(int i=sizes-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

void quicksort(int *a,int sizes){
	stack<pair<int,int> >sta;
	sta.push(make_pair(0,sizes-1));
	while(!sta.empty()){
		int op=0;
		int left=sta.top().first;
		int right=sta.top().second;
		sta.pop();
		int i=left;
		int j=right;
		if(right-left<=3){
			paoooo(a+left,right-left+1);
			continue;
		}
		int tmp=a[left];
		int ryes=1,lyes=1;
		while(i!=j){
			int aj=a[j];
			int ai=a[i];
			while(a[j]>=tmp&&i<j){
				if()
			}
			while(a[i]<=tmp&&i<j){

			}
			if(i<j){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		
		a[left]=a[i];
		a[i]=tmp;
		if((i-left) > (right-j)){
			sta.push(make_pair(j+1,right));
			sta.push(make_pair(left,i-1));
		}
		else {
			sta.push(make_pair(left,i-1));
			sta.push(make_pair(j+1,right));
		}
	}
}

int main(){
	//freopen("xxxxin.txt","r",stdin);
	//freopen("xxxxout.txt","w",stdout);
	Link<int>a;  //no_5
	for(int i=0;i<10;i++){
		int t;
		cin>>t;
		a.insert(t);
	}
	a.bsort();
	a.print();
	cout<<endl;

	XSB<int>aa(100);//9_8
	int b[10];
	FOR(i,10)cin>>b[i];
	aa.insert(b,10);
	aa.csort();
	aa.print();

	cout<<"999999999999"<<endl;
	int a9[12];
	for(int i=0;i<10;i++)cin>>a9[i];
	quicksort(a9,10);
	for(int i=0;i<10;i++)cout<<a9[i]<<" ";
	cout<<endl;

	return 0;
}

//1 4 19 5 8 31 45 6 2 3

