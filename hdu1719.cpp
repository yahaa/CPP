
 
Online Judge	Online Exercise	Online Teaching	Online Contests	Exercise Author
F.A.Q
Hand In Hand
Online Acmers	
Forum | Discuss
Statistical Charts
Problem Archive
Realtime Judge Status
Authors Ranklist

 Search
     C/C++/Java Exams     
ACM Steps
Go to Job
Contest LiveCast
ICPC@China
Best Coder beta
VIP | STD Contests
Virtual Contests 
    DIY | Web-DIY beta
Recent Contests
Author maik000
Mail Mail 0(0)
Control Panel Control Panel 
Sign Out Sign Out
New~ 欢迎参加2016多校联合训练的同学们~ 
View Code

Problem : 1719 ( Friend )     Judge Status : Wrong Answer
RunId : 18091791    Language : G++    Author : maik000
Code Render Status : Rendered By HDOJ G++ Code Render Version 0.01 Beta
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int mx=2005;
bool prime[mx];
int p[mx];
int cp;
void getprime(){
    memset(prime,true,sizeof(prime));
    cp=0;
    for(int i=2;i<mx;i++){
        if(prime[i]){
            p[cp++]=i;
            for(int j=i+i;j<mx;j+=i)prime[j]=false;
        }
    }
}


bool getAns(ll a){
    for(int i=0;i<2;i++){
        while(a%p[i]==0){
            a/=p[i];
        }
    }
    return a==1;
}


int main(){
    getprime();
    ll n;
    while(cin>>n){
        if(n==0){
            cout<<"NO!"<<endl;
            continue;
        }
        bool ans=getAns(++n);
        if(ans)cout<<"YES!"<<endl;
        else cout<<"NO!"<<endl;
    }
    return 0;
}