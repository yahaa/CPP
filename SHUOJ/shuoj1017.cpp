#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=105;
ll a[maxn],b[maxn],temp[maxn];

void multiply(ll *a){
	memset(temp,0,sizeof(temp));
	int k;
	for(int i=0;i<100;i++){
		k=i;
		int ins=0;
		for(int j=0;j<100;j++){
			temp[k]=temp[k]+a[i]*b[j]+ins;
			ins=temp[k]/100000;
			if(k<100)temp[k++]%=100000;
			else temp[k]%=100000;
		}
	}
	copy(temp,temp+100,a);
}

void exp(int p){   
	a[0]=1;
	b[0]=2;
    while(p){   
    	if(p&1){
    		multiply(a);
    	}
    	multiply(b);
    	p>>=1;
    }
}
int main(){
	int p;
	while(scanf("%d",&p)!=EOF){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		exp(p);
		a[0]--;
		int lent=p*log(2.0)/log(10.0)+1;
		printf("%d\n",lent);
		int c=0;
        for(int i=99;i>=0;i--){
            printf("%05lld",a[i]);
            c++;
            if(c%10==0)printf("\n");
        }
	}
	return 0;
}