#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class three {
public:
	int ai,bi,maxc;
};
bool cmp(three a,three b){
	return a.maxc>b.maxc;
}
int main(){
	int t;
	cin>>t;
	three a[1000];
	int index;
	while(t--){
		index=0;
		int total,number,ai,bi;
		cin>>total>>number;
		while(number--){
			cin>>ai>>bi;
			a[index].ai=ai;
			a[index].bi=bi;
			a[index++].maxc=abs(ai-bi);
		}
		sort(a,a+index,cmp);
		for(int i=0;i<index;i++){
			if(a[i].bi<=total)total-=a[i].ai;
			else {
				total-=a[i].bi;
				break;
				}
			}
			if(total>=0)cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
	}
	return 0;
}