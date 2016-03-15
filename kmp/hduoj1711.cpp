#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m;
int pat[10001],ob[1000001],nexts[10001];
void getNext(){
	int j = 0, k = -1;             
	nexts[0] = -1;                     
	while (j<m-1){
		if (k == -1 || pat[k] == pat[j]){
			nexts[++j]=++k;
			 // j++;
			 // k++;
			 // if(pat[j]==pat[k])nexts[j]=nexts[k];
			 // else nexts[j]=k;
		}
		else k = nexts[k];
	}
}


int KMP(){
	getNext();
	int i=0,k=0;
	while(i < n&& k < m){
		if (k==-1||pat[k] == ob[i]){       
			i++;    
			k++;
		}
		else k =nexts[k];
	}
	if (k<m)return -1;
	else return i - k;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>ob[i];
		}
		for(int i=0;i<m;i++){
			cin>>pat[i];
		}
		int ans=KMP();
		if(ans==-1)cout<<ans<<endl;
		else cout<<ans+1<<endl;
	}
	return 0;
}