#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using  namespace std;
const int maxn=999999+1;
int a[maxn];
int main(){
	int n;
	while(cin>>n){
		memset(a,0,sizeof(a));
		int ans=(n+1)/2,tn=n;
		while(n--){
			int index;
			cin>>index;
			a[index]++;
		}
		int  tans=0;
		for(int i=0;i<tn;i++){
			if(a[i]>=ans){
				tans=i;
			}
		}
		cout<<tans<<endl;
	}
	return 0;
}