#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=55;
int value[maxn],num[maxn];
const masum=100000;
int c1[masum],c2[masum];
int main(){
	int n;
	while(cin>>n&&n>0){
		int total=0;
		for(int i=0;i<n;i++){
			cin>>value[i]>>num[i];
			total+=value[i]*num[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		int t=total/2;
		for(int i=0;i<=t;i+=value[0]){
			c1[i]=1;
			c2[i]=0;
		}
		
		for(int i=1;i<n;i)
	}
}