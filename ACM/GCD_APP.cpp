#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
const int maxn=1000010;
struct node{
    int l,r;
    ll gcd;
}Tree[maxn<<2];
ll a[maxn];
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
void pushup(int rt)
{
    Tree[rt].gcd=gcd(Tree[rt*2].gcd,Tree[rt*2+1].gcd);
}
void Build(int l,int r,int rt)
{
    Tree[rt].l=l,Tree[rt].r=r;
    if(l==r)
    {
        Tree[rt].gcd=a[l];
        return ;
    }
    int mid=(l+r)/2;
    Build(l,mid,rt*2);
    Build(mid+1,r,rt*2+1);
    pushup(rt);
}
ll queryans(int L,int R,int rt)
{
    if(L<=Tree[rt].l&&Tree[rt].r<=R)
    {
        return Tree[rt].gcd;
    }
    int mid=(Tree[rt].l+Tree[rt].r)/2;
    ll ans=0;
    if(L<=mid) ans=gcd(ans,queryans(L,R,rt*2));
    if(mid<R)  ans=gcd(ans,queryans(L,R,rt*2+1));
    return ans;
}
int n;
map<ll,ll>ans;
map<ll,ll>mp1;//mp1代表以x[i]结尾的所有区间的gcd的个数
map<ll,ll>mp2;//临时变量

int main()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d",&n);
        ans.clear();
        mp1.clear();
        mp2.clear();
        for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
        Build(1,n,1);
        //puts("success");
        mp1[a[1]]++;
        ans[a[1]]++;
        for(int i=2; i<=n; i++)
        {
            ll now=a[i];
            mp2[now]++;
            ans[now]++;
            for(map<ll,ll>::iterator it=mp1.begin(); it!=mp1.end(); it++)
            {
                int nex=gcd(now,it->first);
                ans[nex]+=it->second;
                mp2[nex]+=it->second;
            }
            mp1.clear();
            for(map<ll,ll>::iterator it=mp2.begin(); it!=mp2.end(); it++)
            {
                mp1[it->first]=it->second;
            }

            //  for(map<ll,ll>::iterator it=mp1.begin(); it!=mp1.end(); it++){
            //     cout<<it->first<<" "<<it->second<<endl;
            // }
            // cout<<"#############"<<endl;
            mp2.clear();
        }


                
        int q;
        printf("Case #%d:\n",cas++);
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            ll temp=queryans(l,r,1);
            printf("%lld %lld\n",temp,ans[temp]);
        }
    }
}