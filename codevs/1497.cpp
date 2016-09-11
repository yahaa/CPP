#include <iostream>
#include <cstdio>
using namespace std;
long long a ,b,k;
long long pows(long long a,long long b,long long k){
    long long ans=1;
    while(b){
        if(b&1){
            ans=(ans%k*a%k)%k;
        }
        a=(a%k*a%k)%k;
        b=b>>1;
    }
    return ans;
}

int main(){
    cin>>a>>b>>k;
    printf("%lld^%lld mod %lld=%lld\n",a,b,k,pows(a,b,k));
    return 0;
}