#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN=50;

int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
bool free_x[MAXN];//标记是否是不确定的变元


inline int gcd(int a,int b){
    int t;
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

inline int lcm(int a,int b){
    return a/gcd(a,b)*b;//先除后乘防溢出
}

// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
void Gauss(int equ,int var){
    int i,j,k;
    int max_r;// 当前这列绝对值最大的行.
    int col;//当前处理的列
    int ta,tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;

    for(int i=0;i<=var;i++){
        x[i]=0;
        free_x[i]=true;
    }

    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0;k < equ && col < var;k++,col++){
        max_r=k;
        for(i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k){
            for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0){
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++){
            if(a[i][col]!=0){
               
                for(j=col;j<var+1;j++){
                    a[i][j] ^=a[k][j];
                }
            }
        }
    }

   
   
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    // if ans ==-2  the type value of x1 x2 x2...is double;
    for (i = var - 1; i >= 0; i--){
        x[i]=a[i][var];
        for(j=i+1;j<var;j++)
          x[i]^=(a[i][j]&&x[j]);
    
    }

}

void initr(){
    for(int i=0;i<5;i++)
       for(int j=0;j<6;j++){
           int t=i*6+j;
           a[t][t]=1;
           if(i>0)a[(i-1)*6+j][t]=1;
           if(i<4)a[(i+1)*6+j][t]=1;
           if(j>0)a[i*6+j-1][t]=1;
           if(j<5)a[i*6+j+1][t]=1;
       }
}

int main(){
	int t;
	cin>>t;
	int tt=1;
	while(t--){
		
		memset(a,0,sizeof(a));
		initr();
		for(int i=0;i<30;i++){
			cin>>a[i][30];
		}
		Gauss(30,30);
		int k=0;
		printf("PUZZLE #%d\n",tt++);
		for(int i=0;i<5;i++){
			for(int j=0;j<6;j++){
				if(j!=5)cout<<x[k++]<<" ";
				else cout<<x[k++]<<endl;
			}
		}
	}
	return 0;
}