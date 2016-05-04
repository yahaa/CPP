/*************************************************************************
  > File Name: tt.cpp
  > Author: yahaa
  > Mail: yuanzihua0@gmail.com 
  > Created Time: 2016年04月28日 星期四 10时39分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
	int a;
	cin>>a; 
	cout<<a<<endl;
	if(a)cout<<1000<<endl;
	else cout<<2000<<endl;
	while(a--){
		cout<<199+a<<endl;		
	}
	for(int i=0;i<100;i++){
		cin>>a;
		cout<<a<<endl;
	}
	return 0; 
}
