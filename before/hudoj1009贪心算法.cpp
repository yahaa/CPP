#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std; 
struct node{
	double total, need, value;
};
bool compare(node a, node b){ 
	return a.value > b.value;
}
int main(){
	node ta[1001];
	double m;
	int n;
	double ans;
	while (cin >> m >> n&&n >= 0 && m >= 0){
		ans = 0;
		for (int i = 0; i < n; i++){
			cin >> ta[i].total >> ta[i].need;
			ta[i].value = ta[i].total / ta[i].need;
		}
		sort(ta, ta + n, compare);
		for (int i = 0; i < n&&m; i++){
			if (ta[i].need <=m){
				ans += ta[i].total;
				m -= ta[i].need;
				ta[i].total = 0;
			}
			else {
				ans += m*ta[i].value;
				m = 0;
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}