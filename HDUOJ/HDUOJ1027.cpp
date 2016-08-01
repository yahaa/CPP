#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
using namespace std;
const int maxn=1005;
int main(){
	int n,m;
	int a[maxn];
	while(cin>>n>>m){
		for(int i=1;i<=n;i++)a[i-1]=i;
		int count=0;
		do{	
			count++;
			if(count==m){
				for(int i=0;i<n;i++){
					if(i!=n-1)cout<<a[i]<<" ";
					else cout<<a[i]<<endl;
				}
				break;
			}

		}while(next_permutation(a,a+n));
	}
	return 0;
}