#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<fstream>
using namespace std;
int v1, v2, v3;
int visted[21][21][21];
vector<int>ans;
void puss(int v, int &a, int&b){
	if (a + b >v){
		b = a + b - v;
		a = v;
	}
	else {
		a = a + b;
		b = 0;
	}
}
void solve(int x, int y, int z){
	if (x == 0)ans.push_back(z);
	if (visted[x][y][z])return;
	visted[x][y][z] = 1;
	int a = x, b = y, c = z;
	puss(v1, a, c);
	solve(a, b, c);

	a = x, b = y, c = z;
	puss(v2, b, c);
	solve(a, b, c);

	a = x, b = y, c = z;
	puss(v1, a, b);
	solve(a, b, c);

	a = x, b = y, c = z;
	puss(v3, c, b);
	solve(a, b, c);

	a = x, b = y, c = z;
	puss(v2, b, a);
	solve(a, b, c);

	a = x, b = y, c = z;
	puss(v3, c, a);
	solve(a, b, c);

}
int main(){
	while (cin >> v1>> v2>> v3){
		ans.clear();
		memset(visted, 0, sizeof(visted));
		solve(0, 0, v3);
		sort(ans.begin(), ans.end());
		int n = unique(ans.begin(), ans.end()) - ans.begin();
		for (int i = 0; i <n; i++){
			if (i ==n-1)cout << ans[i] << endl;
			else cout << ans[i] << " ";
		}
	}
	return 0;
}



#include<iostream>
using namespace std;
int main(){
	int n;
	while (cin >> n&&n){
		if (n <= 4)cout << 1 << endl;
		else cout << (n - 1) / 2 << endl;
	}
	return 0;
}
