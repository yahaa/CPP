#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
/*
    思路：由于每个点只能走一次，所以很容易想到 哈密顿图旅行商问题
    把3*3的格子编号 为 0---8 的九个点抽象成哈密顿图，然在图中找路径长度为1---9 的总的方案数
*/
int dp[1<<10][10],len[1<<10],sum[10];//len数组保存 不同集合 s 所对应的节点数

bool appear(int s,int b){//判断 b 是否在已经走过的 s 集合中出现过
    return (s>>b)&1; 
}

bool check(int s,int t,int maks){  //判断从 s点可否走到 t点
     int rs=s/3,cs=s%3;  //把点 s,t 分解为 3*3 的 格子的坐标位置
     int rt=t/3,ct=t%3;
     int tx=abs(rs-rt);
     int ty=abs(cs-ct);
     if(tx+ty==1)return true;//判断他们的相对位置  
     if(tx*ty==1||tx*ty==2) return true;
     if(tx*ty==4)return appear(maks,4);
     if(tx==0)return appear(maks,3*rs+1);
     if(ty==0)return appear(maks,3+cs);
}

int main(){
    
    memset(sum,0,sizeof(sum));
    for(int i=0;i<9;i++)dp[1<<i][i]=1;
    for(int i=0;i<(1<<9);i++)len[i]=len[i/2]+i%2;

    for(int i=0;i<(1<<9);i++){
        for(int j=0;j<9;j++){
            sum[len[i]]+=dp[i][j];   //dp[i][j]表示为  当前集合为 i ,当前走到的点 为 j
            for(int k=0;k<9;k++){   //判断从当前的点 j 能否走到下一个点 k
                if(!appear(i,k)){
                    if(check(j,k,i))
                        dp[i+(1<<k)][k] += dp[i][j];
                }
            }
        }
    }
  
    for(int i=1;i<=9;i++){
        cout<<sum[i]<<endl;
    }
    return 0;
}

//O(2^9*9^2)