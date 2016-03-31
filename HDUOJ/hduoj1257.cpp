#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	vector<int>a;
	while(cin>>n){
		a.clear();
		int t;
		for(int i=0;i<n;i++){
			cin>>t;
			sort(a.begin(),a.end());
			int j=0;
			for(j=0;j<a.size();j++){
				if(t<=a[j]){
					a[j]=t;
					break;
				}
			}
			if(j>=a.size())a.push_back(t);
		}
		cout<<a.size()<<endl;
	}
	return 0;
}