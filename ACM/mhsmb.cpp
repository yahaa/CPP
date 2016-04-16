#include <iostream>  
#include <cstring>
#include <cstdio>
using namespace std;  
typedef long long ll;
const int maxn= 10001;   
ll c1[maxn], c2[maxn];//c1[i]的下标表示的是该项的次数，c1[i]的值表示的是该项的系数
//母函数　　G(X)=(1+X+X^2+X^3+...)(1+X^2+X^4+...)(1+X^3+X^6+...)...(1+X^n+x^2n+...)
//           =1+a1x^1+a2x^2+a3x^3+...
int main(){  
   int t;
   cin>>t;
   int tt=1;
   int cper,sum,per;
   while(t--){
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        cin>>cper>>sum>>per;
        for(int i=0; i<=sum; i+=per){  //第一个括号内　所有的项的系数都初始化为１
            c1[i] = 1;  
            c2[i] = 0;  
        }

        for(int i=2; i<=cper; ++i){//有多少种面值，所以有　　cper 个括号，对
            cin>>per;
            for(int j=0; j<=sum; ++j){//模拟多项式乘法　　　j k表示的都是次数
                for(int k=0; k+j<=sum; k+=per){  //k表示第 i 个括号内的各项的次数
                    c2[j+k] += c1[j];  //下标相加表示指数相加
                }   
            }
            for(int j=0; j<=sum; ++j){//每一次乘完都更新到当前乘完的项
                c1[j] = c2[j];  
                c2[j] = 0;  
            }  
        } 
        printf("Case #%d: %lld\n",tt++,c1[sum]);
   }
    return 0;  
}  


