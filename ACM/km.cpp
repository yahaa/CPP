#include <iostream>   
using namespace std;   
int modexp(int a,int b){   
    int ret=1;   
    int tmp=a;   
    while(b){   
       if(b&1){
        ret=ret*tmp;
      }
       tmp=tmp*tmp;
       b>>=1;
    }
    return ret;   
}
int main(){
    cout<<modexp(2,20)<<endl;   
    return 0;
}
