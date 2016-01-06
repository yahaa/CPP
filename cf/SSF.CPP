#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int gun[10005];
	while(cin>>n){
		int x,k=0;
		while(n--){
			cin>>x;
		if(k==0){
			gun[k++]=x;
		}

		else{
			sort(gun,gun+k);
			int i;
			for(i=0;i<k;i++){
				if(x<=gun[i]){
					gun[i]=x;
					break;
				}
			}

			if(i>=k)gun[k++]=x;
		}
		}
		
		cout<<k<<endl;
	}
	return 0;
}