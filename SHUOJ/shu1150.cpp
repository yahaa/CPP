// //A
// #include <iostream>
// using namespace std;
// int GCD(int a,int b){
// 	if(b==0)return a;
// 	return GCD(b,a%b);
// }
// int main(){
// 	int t;
// 	cin>>t;
// 	int a,b;
// 	while(t--){
// 		cin>>a>>b;
// 		b=b%a;
// 		cout<<a/GCD(a,b)<<endl;
// 	}
// 	return 0;
// }
// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <cstring>
// using namespace std;
// int main(){
// 	int t;
// 	cin>>t;
// 	string s;
// 	while(t--){
// 		cin>>s;
// 		int len=s.length();
// 		int count=0,count9=0;
// 		for(int i=0;i<s.length();i++){
// 			if(s[i]=='8')count++;
// 			if(s[i]=='9')count9++;
// 		}

// 		if(len<=3){
// 			if(count9>=1&&len==3)cout<<1888<<endl;
// 			else cout<<888<<endl;
// 		}
// 		else {
// 			if(count==3)cout<<s<<endl;
// 			else if(count>3){
// 				int t8=0;
// 				for(int i=0;i<s.length();i++){
// 					if(t8<3&&s[i]=='8')t8++;
// 					else if(t8>=3&&s[i]=='8'){
// 						if(t8==3)s[i]='9';
// 						else s[i]='0';
// 						t8++;
// 					}
// 				}
// 				cout<<s<<endl;
// 			}
// 			else {
// 				char a[1000],b[1000];
// 				int l;
// 				for(l=0;l<s.length();l++)a[l]=b[l]=s[l];
// 				int in=0;
// 				int t9=0,f=0;
// 				int t8=count;
// 				for(int i=l-1;i>=0;i--){
// 					if(t8<3){
// 						if(a[i]!='8'){
// 							if(a[i]=='9'){
// 								t9++;
// 								f++;
// 							}
// 							a[i]='8';
// 							t8++;
// 						}
// 					}
// 					else{
// 						if(t9==0)break;
// 						if(strcmp(a,b)>0)break;
// 						else {
// 							if(f){
// 								int temp=a[i]+1-'0'+in;
// 								a[i]=(char)(temp%10+'0');
// 								in=temp/10;
// 								f=0;
// 							}
// 							else {
// 								int temp=a[i]-'0'+in;
// 								a[i]=(char)(temp%10+'0');
// 								in=temp/10;
// 							}
// 						}
// 					}
// 				}
// 				if(in)cout<<in;
// 				for(int i=0;i<l;i++)cout<<a[i];
// 				cout<<endl;
// 			}
// 		}
// 	}
// 	return 0;
// }
//B
#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=n-2;i>=0;i--){
			if(a[i+1]-1>a[i]){
				int temp=a[i];
				a[i]=a[i+1]-1;
				a[i+1]=temp+1;
			}
		}
		int ans=1;
		for(int i=0;i<n-1;i++){
			if(a[i+1]>a[i]){
				ans=0;
				break;
			}
		}

		if(ans){
			for(int i=0;i<n;i++){
				if(i==n-1)cout<<a[i]<<endl;
				else cout<<a[i]<<" ";
			}
		}
		else cout<<"Impossible"<<endl;

	}
	return 0;

}