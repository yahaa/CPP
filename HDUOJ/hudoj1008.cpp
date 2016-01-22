#include<iostream>
using namespace std; 
int main(){
	int n;
	int a[101];
	int ans;
	a[0] = 0;
	while (cin >> n&&n){
		ans = 0;
		for (int i = 1; i <=n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++){
			if (a[i] - a[i - 1] > 0){
				ans += (a[i] - a[i - 1]) *6+5;
				
			}
			else {
				ans += (a[i - 1] - a[i]) * 4 + 5;
				
			}
		}
		cout << ans << endl;
	}
	return 0;
}