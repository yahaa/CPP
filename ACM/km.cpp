#include <iostream>   
using namespace std;   
int modexp(int a,int b){   
    int ret=1;   
    int tmp=a;   
    while(b){   
       if(b&1){ret=ret*tmp;ret%=1000;}
       tmp=tmp*tmp;
       tmp%=1000;
       b>>=1;
    }
    return ret;   
}
int main(){
    cout<<modexp(6789,10000)%1000<<endl;   
    return 0;
}
