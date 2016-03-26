#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=101;
int C[maxn][maxn];
void init(){                  //跑一趟动态规划    先把后面要求的组合数的值求出来   
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1]= 1;
	for (int i = 2; i <maxn; i++){
		C[i][0] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		C[i][i] = 1;
	}
}
int main(){
	init();
	int n;
	char ch[maxn][maxn];
	while(cin>>n){
		getchar();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)cin>>ch[i][j];

		int ans=0;
		for(int i=0;i<n;i++){
			int tt=0;
			for(int j=0;j<n;j++){
				if(ch[i][j]=='C')tt++;
			}
			if(tt>=2)ans+=C[tt][2];
		}

		for(int j=0;j<n;j++){
			int tt=0;
			for(int i=0;i<n;i++){
				if(ch[i][j]=='C')tt++;
			}
			if(tt>=2)ans+=C[tt][2];
		}
		cout<<ans<<endl;
	}
	return 0;

}