// #include <iostream>
// #include <string>
// #include <cmath>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxn=1002;
// int a[maxn][maxn];
// int b[maxn][maxn];
// int main(){
// 	int n,m,t,nx,mx;
// 	while(scanf("%d%d",&n,&m)!=EOF){
// 		memset(a,0,sizeof(a));
// 		memset(b,0,sizeof(b));
// 		for(int i=1;i<=n;i++){
// 			for(int j=1;j<=m;j++){
// 				scanf("%d",&a[i][j]);
// 				a[i][j]+=a[i][j-1];
// 				b[i][j]=a[i][j];
// 				b[i][j]+=b[i-1][j];
// 			}
// 		}
// 		scanf("%d%d",&nx,&mx);
// 		int ans=0;
// 		for(int i=nx;i<=n;i++){
// 			for(int j=mx;j<=m;j++){
// 				ans=max(ans,b[i][j]-b[i][j-mx]-b[i-nx][j]+b[i-nx][j-mx]);
// 			}
// 		}
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int a[100000];
	while(cin>>n){
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(i!=n-1)cout<<a[i]<<" ";
			else cout<<a[i]<<endl;
		}
	}
	return 0;
}

