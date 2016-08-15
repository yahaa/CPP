/*************************************************************************
	> File Name: hdu1721.cpp
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
	> Created Time: 2016年08月15日 星期一 10时54分18秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <fstream>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;

int main(){
    int a,b,c,d,e,f,g,h;
    while(cin>>a){
    	if(a==-1)break;
    	cin>>b>>c>>d>>e>>f>>g>>h;
    	int sum1=a+c+f+h;
    	int sum2=b+d+e+g;
    	if(sum1!=sum2)cout<<"Sorry,it can't be cleared away!"<<endl;
    	else cout<<"All the seeds can be cleared away!"<<endl;
    }
   
    return 0;
}

