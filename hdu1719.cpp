
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int mx=2005;
bool prime[mx];
int p[mx];
int cp;
void getprime(){
    memset(prime,true,sizeof(prime));
    cp=0;
    for(int i=2;i<mx;i++){
        if(prime[i]){
            p[cp++]=i;
            for(int j=i+i;j<mx;j+=i)prime[j]=false;
        }
    }
}


bool getAns(ll a){
    for(int i=0;i<2;i++){
        while(a%p[i]==0){
            a/=p[i];
        }
    }
    return a==1;
}


int main(){
    getprime();
    int n;
    while(cin>>n){
        if(n==0){
            cout<<"NO!"<<endl;
            continue;
        }
        bool ans=getAns(++n);
        if(ans)cout<<"YES!"<<endl;
        else cout<<"NO!"<<endl;
    }
    return 0;
}