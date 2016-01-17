#include <iostream>   
using namespace std;   
int modexp(int a,int b,int n){   
    int ret=1;   
    int tmp=a;   
    while(b){   
       if(b%2==1)ret=ret*tmp%n;
       tmp=tmp*tmp%n;
       b>>=1;
    }
    return ret;   
}
int main(){
    cout<<modexp(2,10,3)<<endl;   
    return 0;
}
