#include <iostream>  

using namespace std;  
const int maxn= 10001;   
int c1[maxn], c2[maxn]; 
void   muhanshu(int n){
     int i, j, k;
    for(i=0; i<=n; ++i){  
            c1[i] = 1;  
            c2[i] = 0;  
        }

    for(i=2; i<=n; ++i){  
        for(j=0; j<=n; ++j) 
            for(k=0; k+j<=n; k+=i){  
                c2[j+k] += c1[j];  
            }  
            for(j=0; j<=n; ++j){  
                c1[j] = c2[j];  
                c2[j] = 0;  
             }  
    }  
}
int main(){  
    int nNum;
    
    while(cin >> nNum)  { 
        muhanshu(nNum); 
        cout << c1[nNum] << endl;  
    }  
    return 0;  
}  
