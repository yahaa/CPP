// // #include <iostream>
// // #include <map>
// // #include <string>
// // using namespace std;
// // map<string,int>mon;
// // int main(){
// // 	mon["JAN"]=31;mon["FEB"]=28;
// // 	mon["MAR"]=31;mon["APR"]=30;
// // 	mon["MAY"]=31;mon["JUN"]=30;
// // 	mon["JUL"]=31;mon["AUG"]=31;
// // 	mon["SEP"]=30;mon["OCT"]=31;
// // 	mon["NOV"]=30;mon["DEC"]=31;
// // 	mon["MON"]=1;mon["TUE"]=2;
// // 	mon["WED"]=3;mon["THU"]=4;
// // 	mon["FRI"]=5;mon["SAT"]=6;mon["SUN"]=7;
// // 	int N;cin>>N;
// // 	while(N--){
// // 		int ans=0;
// // 		string s1,s2;
// // 		cin>>s1>>s2;
// // 		int ds=mon[s1],d=mon[s2];
// // 		for(int i=d;i<ds+d;i++){
// // 			if(i%7==6||i%7==5)ans++;
// // 		}
// // 		cout<<ans<<endl;
// // 	}
// // 	return 0;
// // }
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// class nu
// {
// public:
// 	int a;
// 	char b,c;
// };
// bool cmp (nu a,nu b)
// {
// 	return a.a<b.a;
// }
// int main()
// {
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		int n;
// 		cin>>n;
// 		nu A[100000];
// 		int s[100];
// 		memset(s,0,sizeof(s));
// 		for(int i=0;i<n;i++)
// 		{
// 			cin>>A[i].a>>A[i].b>>A[i].c;
// 			if(A[i].b=='1'&&A[i].c=='c')s[A[i].a]++;
// 		}
// 		sort(A,A+n,cmp);
// 		int sum=0;
// 		//for(int i=1;i<=10;i++)cout<<s[i];
// 		for(int i=0;i<n;i++)
// 		{
// 			if(A[i].b=='0'&&A[i].c=='i')
// 				{
// 					for(int j=A[i].a+1;j<=10;j++)sum+=s[j];
// 						//cout<<'*'<<A[i].a;
// 				}

// 		}
// 		cout<<sum<<endl;
// 	}
// 	return 0;
// }

// #include <iostream>
// #include <cstring>
// #include <string>
// using namespace std;
// int a[30];

// int main(){
// 	int N;cin>>N;
// 	int C=0;
// 	while(N--){
// 		string s="";
// 		cin>>s;
// 		memset(a,0,sizeof(a));
// 		for(int i=0;i<s.length();i++){
// 			a[s[i]-'a']++;
// 		}
// 		int minn=1000010;
// 		for(int i=0;i<26;i++){
// 			if(a[i]==0){
// 				minn=0;
// 				break;
// 			}else{
// 				minn=min(minn,a[i]);
// 			}
// 		}
// 		cout<<"Case "<<++C<<": "<<minn<<endl;
// 	}
// 	return 0;
// }
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

long long ans;

long long solve(long long n){
	if(n==1)return 1;
	long long x=n/2,y=n-x;
	return solve(y)+(x+1+n)*x/2;
}



int main(){
	long long N;
	while(scanf("%lld",&N)==1&&N){
		ans=N-1;
		// for(int i=2;i<=N;i++){
		// 	ans+=i*(N/i);
		// }
		// cout<<ans<<endl;
		printf("%lld\n",solve(N));
	}
	return 0;
}
