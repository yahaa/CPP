#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int maxn=500005;
int b[maxn];
int n;
void add(int i,int v){
	while(i<=n){
		b[i]+=v;
		i+=i&-i;
	}
}

int sum(int i){
	int s=0;
	while(i>0){
		s+=b[i];
		i-=i&-i;
	}
	return s;
}

struct no{
	int value;
	int ini;
	int soi;
};

bool cmp(no a,no b){
	return a.value<b.value;
}

bool cmp1(no a,no b){
	return a.ini<b.ini;
}



no a[maxn];

int main(){
	while(cin>>n&&n){
		memset(b,0,sizeof(b));

		for(int i=0;i<n;i++){
			scanf("%d",&a[i].value);
			a[i].ini=i;
		}
		
		sort(a,a+n,cmp);
	
		for(int i=0;i<n;i++){
			a[i].soi=i+1;
		}
		sort(a,a+n,cmp1);
	
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i].soi-1-sum(a[i].soi);
			cout<<sum(a[i].soi)<<"tttt"<<endl;
			add(a[i].soi,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
	
}