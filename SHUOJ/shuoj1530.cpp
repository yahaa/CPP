// #include <iostream>
// #include <cstring>
// #include <cmath>
// #include <string>
// using namespace std;
// const int maxn=40001;
// int maps[maxn];


// int main(){
// 	for(int i=1;i<=10000;i++){
// 		maps[(int)(i*log(i*1.0)/log(10.0)+1)]=i;
// 	}
// 	string s;
// 	while(cin>>s){

// 	}

// }



#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=40001;
int maps[maxn];
typedef unsigned long long ll;
ll a[maxn],b[maxn],temp[maxn];
int len;

void multiply(ll *a){
	memset(temp,0,sizeof(temp));
	int k;
	for(int i=0;i<len;i++){
		k=i;
		int ins=0;
		for(int j=0;j<len;j++){
			temp[k]=temp[k]+a[i]*b[j]+ins;
			ins=temp[k]/100000000;
			if(k<len)temp[k++]%=100000000;
			else temp[k]%=100000000;
		}
	}
	copy(temp,temp+len,a);
}

void exps(int p){   
	a[0]=1;
	b[0]=p;
    while(p){   
    	if(p&1){
    		multiply(a);
    	}
    	multiply(b);
    	p>>=1;
    }
}
int main(){
	for(int i=1;i<=10000;i++){
		maps[(int)(i*log(i*1.0)/log(10.0)+1)]=i;
	}
	string s;
	while(cin>>s){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		len=s.length();
		int p=maps[len];
		exps(p);
		cout<<maps[len]<<endl;
		string ans;
        for(int i=len-1;i>=0;i--){
            ll t=a[i];
            string ts;
            int count=0;
            do{
            	ts+=(t%10+'0');
            	t/=10;
            	count++;
            }while(t>0);
           while(count<8)ts+='0';
           reverse(ts.begin(),ts.end());
           ans+=ts;
        }
        for(int i=0;i<len;i++){
        	cout<<ans[i];
        }

    }
}