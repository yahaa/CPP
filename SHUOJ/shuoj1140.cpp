#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	vector<pair<int, int> >a;
	while (cin >> t){
		while (t--){
			a.clear();
			a.push_back(make_pair(-1, -1));
			int n, k;
			cin >> n >> k;
			int ti, apples;
			for (int i = 1; i <= n; i++){
				cin >> ti >> apples;
				a.push_back(make_pair(ti, apples));
			}
			sort(a.begin(), a.end());
			int ans = 0;
			int i = n;
			while (i > 0){
				while (a[i].second > 0){
					ans += a[i].first * 2;
					a[i].second -= k;
				}
				while (a[i].second <= 0){
					a[i - 1].second += a[i].second;
					i--;
					if (i == 0)break;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}