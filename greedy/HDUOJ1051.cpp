#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=5000;
struct two{
    int length,weigth;
};

bool cmp(two a,two b){
    if(a.length==b.length)return a.weigth<b.weigth;
    return a.length<b.length;
}

int used[maxn];
int main(){
    int t;
    cin>>t;
    two a[maxn];
    while(t--){
        memset(used,0,sizeof(used));
        int n;
        cin>>n;
        int length,weigth;
        for(int i=0;i<n;i++){
            cin>>length>>weigth;
            a[i].length=length;
            a[i].weigth=weigth;
        }
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!used[i]){
                used[i]=1;
                ans++;
                int tl=a[i].length;
                int tw=a[i].weigth;
            for(int j=i;j<n;j++){
                if(used[j])continue;
                else if(tl<=a[j].length&&tw<=a[j].weigth){
                    used[j]=1;
                    tl=a[j].length;
                    tw=a[j].weigth;
                }
            }
        }
        }
        cout<<ans<<endl;
    }
    return 0;
}