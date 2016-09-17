#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
	int a[4];
	int tt=0;
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)break;
		if(tt!=0)cout<<endl;
		tt++;
		while(a[0]==0&&next_permutation(a,a+4));
		int t=a[0];
		int f=1;
		do{
			int t2=a[0];
			if(t2!=t){
				t=a[0];
				cout<<endl;
				f=1;
			}
			if(f++==1)cout<<a[0]<<a[1]<<a[2]<<a[3];
			else cout<<" "<<a[0]<<a[1]<<a[2]<<a[3];
			
		}while(next_permutation(a,a+4));
		cout<<endl;
	}
	return 0;
}


