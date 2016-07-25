#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
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
int Gauss(int equ,int var){
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
                LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb = LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)tb=-tb;//异号的情况是相加
                for(j=col;j<var+1;j++){
                    a[i][j] = a[i][j]*ta-a[k][j]*tb;
                }
            }
        }
    }

    for (i = k; i < equ; i++){ 
        if (a[i][col] != 0) return -1;
    }
   
    if (k < var){
        for (i = k - 1; i >= 0; i--){
            free_x_num = 0;
            for (j = 0; j < var; j++){
                if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1)continue;
            temp = a[i][var];
            for (j = 0; j < var; j++){
                if (a[i][j] != 0 && j != free_index)temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        return var - k; // 自由变元有var - k个.
    }
    // 3. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-2 ... X0.
    int ans=0;// if ans ==-2  the type value of x1 x2 x2...is double;
    for (i = var - 1; i >= 0; i--){
        temp = a[i][var];
        for (j = i + 1; j < var; j++){
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
    if (temp % a[i][i] != 0)ans=-2;
        x[i] = temp / a[i][i];
    }
    return ans;
}


int main(void){
    
    int i, j;
    int equ,var;
    while (scanf("%d %d", &equ, &var) != EOF){
        memset(a, 0, sizeof(a));
        for (i = 0; i < equ; i++){
            for (j = 0; j < var + 1; j++)scanf("%d", &a[i][j]);
        }
        int free_num = Gauss(equ,var);
        if (free_num == -1) printf("无解!\n");
        else if (free_num > 0){
            printf("无穷多解! 自由变元个数为%d\n", free_num);
            for (i = 0; i < var; i++){
                if (free_x[i]) printf("x%d 0\n", i + 1);
                else printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        else{
            for (i = 0; i < var; i++){
                printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        printf("\n");
    }
    return 0;
}