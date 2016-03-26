#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1001;
int t[maxn],q[maxn];
int vist[maxn],visq[maxn];
int main(){
	int n;
	while(cin>>n){
		//memset(vist,0,sizeof(vist));
		memset(visq,0,sizeof(visq));
		for(int i=0;i<n;i++){
			cin>>t[i]>>q[i];
		}
		sort(t,t+n);
		sort(q,q+n);
		int ans=0;
		for(int i=0;i<n;i++){
			int j;
			for(j=n-1;j>=0;j--){
				if(t[i]>=q[j]&&!visq[i]){
					if(t[i]>q[j])ans+=100;
					visq[j]=1;
					break;
				}
				else{
					if(!visq[j]){
						ans-=100;
						visq[j]=1;
						break;
					}
					
				}
			}
			if(j==n)ans+=100;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}