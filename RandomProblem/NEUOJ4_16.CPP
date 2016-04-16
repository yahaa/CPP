


// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
// 	string s;
// 	while(cin>>s){
// 		int n=s.length();
// 		int ans=0;
// 		for(int i=0,j=n-1;i<j;i++,j--){
// 			if(s[i]!=s[j]){
// 				ans=1;
// 				break;
// 			}
// 		}
// 		if(ans)cout<<"NO"<<endl;
// 		else cout<<"Yes"<<endl;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <cstdio>
// using namespace std;
// int main(){
// 	int t;
// 	scanf("%d",&t);
// 	int n;
// 	while(t--){
// 		scanf("%d",&n);
// 		n/=2;
// 		if(n<2)printf("%d\n",n);
// 		else printf("%d\n",(n-2)*4+3);
// 	}
// 	return 0;
// }


// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// using namespace std;

// int GCD(int a,int b){
// 	if(b==0)return a;
// 	return GCD(b,a%b);
// }
// int main(){
// 	int t;
// 	scanf("%d",&t);
// 	int n;
// 	int tt=1;
// 	while(t--){
// 		scanf("%d",&n);
// 		int ans=0;
// 		for(int i=1;i<=n;i++){
// 			if(GCD(i,n)!=1){
// 				ans+=i;
// 			}
// 		}
// 		printf("Case #%d: %d\n",tt++,ans);
// 	}
// 	return 0;
// }



// #include <iostream>
// #include <string>
// using namespace std;
// const int maxn=1000;
// int lch[maxn],rch[maxn];
// char op[maxn];
// int nodes=0;
// int build_tree(string s,int x,int y){
// 	int i,c1=-1,c2=-1,p=0;
// 	int u;
// 	if(y-x==1){
// 		u=++nodes;
// 		lch[u]=rch[u]=0;
// 		op[u]=s[x];
// 		return u;
// 	}

// 	for(i=x;i<y;i++){
// 		switch(s[i]){
// 			case '(':p++;break;
// 			case ')':p++;break;
// 			case '+':case '-':if(!p)c1=i;break;
// 			case '*':case '/':if(!p)c2=i;break;
// 		}
// 	}

// 	if(c1<0)c1=c2;
// 	if(c1<0)return build_tree(s,x+1,y-1);
// 	u=++nodes;
// 	lch[u]=build_tree(s,x,c1);
// 	rch[u]=build_tree(s,c1+1,y);
// 	op[u]=s[c1];
// 	return u;
// }

// void init(){
// 	nodes=0;
// }
// int main(){
// 	string s;
// 	while(cin>>s){
// 		init();
// 		cout<<build_tree(s,0,s.length());
// 		for(int i=0;i<s.length();i++){
// 			cout<<lch[i]<<" "<<op[i]<<" "<<rch[i]<<endl;
// 		}
// 	}
// }


// #include <iostream>  
// #include <cstring>
// #include <cstdio>
// using namespace std;  
// typedef long long ll;
// const int maxn= 10001;   
// ll c1[maxn], c2[maxn];//c1[i]的下标表示的是该项的次数，c1[i]的值表示的是该项的系数
// //母函数　　G(X)=(1+X+X^2+X^3+...)(1+X^2+X^4+...)(1+X^3+X^6+...)...(1+X^n+x^2n+...)
// //			 =1+a1x^1+a2x^2+a3x^3+...
// int main(){  
//    int t;
//    cin>>t;
//    int tt=1;
//    int cper,sum,per;
//    while(t--){
//    		memset(c1,0,sizeof(c1));
//    		memset(c2,0,sizeof(c2));
//    		cin>>cper>>sum>>per;
//     	for(int i=0; i<=sum; i+=per){  //第一个括号内　所有的项的系数都初始化为１
//             c1[i] = 1;  
//             c2[i] = 0;  
//         }

//     	for(int i=2; i<=cper; ++i){//有多少种面值，所以有　　cper 个括号，对
//     		cin>>per;
//        	 	for(int j=0; j<=sum; ++j){//模拟多项式乘法　　　j k表示的都是次数
//             	for(int k=0; k+j<=sum; k+=per){  //k表示第 i 个括号内的各项的次数
//                	 	c2[j+k] += c1[j];  //下标相加表示指数相加
//             	}	
//         	}
//         	for(int j=0; j<=sum; ++j){//每一次乘完都更新到当前乘完的项
//              	c1[j] = c2[j];  
//              	c2[j] = 0;  
//          	}  
//     	} 
//     	printf("Case #%d: %lld\n",tt++,c1[sum]);
//    }
//     return 0;  
// }  

// #include <iostream>   //划分母函数实现方式
// #include <algorithm>
// #include <cstring>
// using namespace std;
// const int maxn=125;
// int c1[maxn],c2[maxn];
// int main(){
// 	int n;
// 	while(cin>>n){
// 		for(int i=0;i<=n;i++){
// 			c1[i]=1;
// 			c2[i]=0;
// 		}

// 		for(int i=2;i<=n;i++){
// 			for(int j=0;j<=n;j++){
// 				for(int k=0;k+j<=n;k+=i){
// 					c2[j+k]+=c1[j];
// 				}
// 			}
// 			for(int j=0;j<=n;j++){
// 				c1[j]=c2[j];
// 				c2[j]=0;
// 			}
// 		}
// 		cout<<c1[n]<<endl;
// 	}
// 	return 0;

// }

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=125;
int dp[maxn][maxn];

int main(){
	int n;
	while(cin>>n){
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j>i)dp[i][j]=dp[i][i];
				else if(i==j)dp[i][j]=1+dp[i][j-1];
				else dp[i][j]=dp[i-j][j]+dp[i][j-1];
			}
		}
		cout<<dp[n][n]<<endl;
	}
	return 0;
}