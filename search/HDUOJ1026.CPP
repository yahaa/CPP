#include <iostream>       //搜索题　广度搜索   bfs
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <stack>
using namespace std;
int n,m;
const int maxn=110;
char maps[maxn][maxn];
int dis[maxn][maxn];
int vist[maxn][maxn];
int vistdfs[maxn][maxn];
int b[maxn][maxn];
int drx[4]={-1,0,0,1};
int dry[4]={0,-1,1,0};
stack<pair<int ,int> >ans;


void init(){
    memset(b,0,sizeof(b));
    memset(dis,0,sizeof(dis));
    memset(vist,0,sizeof(vist));
    memset(vistdfs,0,sizeof(vistdfs));
    while(!ans.empty())ans.pop();
}

void bfs(int x,int y){    //用队列实现
    queue<pair<int,int> >a;
    a.push(make_pair(x,y));
    vist[x][y]=1;
    while(!a.empty()){
        x=a.front().first;
        y=a.front().second;
        a.pop();
        for(int i=0;i<4;i++){
            int tx=x+drx[i];
            int ty=y+dry[i];
            if((tx>=0&&tx<n&&ty>=0&&ty<m)&&maps[tx][ty]!='X'){
                int step=isdigit(maps[tx][ty])?(maps[tx][ty]-'0'+1):1;      //和通常的做法不同的是不用vis数组
                if((dis[tx][ty]==0 &&!(tx==0&&ty==0))|| dis[tx][ty]>dis[x][y]+step){
                    dis[tx][ty]=dis[x][y]+step;  //因为还要比较该走是最优的
                    a.push(make_pair(tx,ty));
                    b[tx][ty]=x+maxn*y;
                }
            }
        }
    }
}

void insterans(){
    int x=n-1;
    int y=m-1;
    while(!(x==0&&y==0)){
        ans.push(make_pair(x,y));
        int temp=x;
        x=b[x][y]%maxn;
        y=b[temp][y]/maxn;
    }
    ans.push(make_pair(0,0));
}

void print(){
    insterans();
    pair<int,int>temp=ans.top();
    ans.pop();
    int t=1;
    while(!ans.empty()){
        if(isdigit(maps[ans.top().first][ans.top().second])){
            printf("%ds:(%d,%d)->(%d,%d)\n",t++,temp.first,temp.second,ans.top().first,ans.top().second);
            int tt=maps[ans.top().first][ans.top().second]-'0';
            while(tt--){
                printf("%ds:FIGHT AT (%d,%d)\n",t++,ans.top().first,ans.top().second);
            }
        }
        else printf("%ds:(%d,%d)->(%d,%d)\n",t++,temp.first,temp.second,ans.top().first,ans.top().second);
        temp=ans.top();
        ans.pop();
    }
}


int main(){
    while(cin>>n>>m){
        init();
        for(int i=0;i<n;i++)cin>>maps[i];
        bfs(0,0);
    
    if(dis[n-1][m-1]){
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",dis[n-1][m-1]);
        print();
    }
    else printf("God please help our poor hero.\n");
    cout<<"FINISH"<<endl;
  }    
    return 0;
}