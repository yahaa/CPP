#include<iostream>
#include<algorithm>
using namespace std;
int n, e[250], f[250][250] = { 0 };
int main()
{
	int i, j, k, mx = 0;
	cin >> n;
	for (i = 1; i <= n; i++){
		cin >> e[i];
		e[n + i] = e[i];
	}
	for (j = 2; j <= 2 * n - 1; j++)
	for (i = j - 1; i>0 && j - i<n; i--)
	for (k = i; k<j; k++)
		f[i][j] = max(f[i][k] + f[k + 1][j] + e[i] * e[k + 1] * e[j + 1], f[i][j]);
	for (i = 1; i <= n; i++)
		mx = max(mx, f[i][i + n - 1]);
	cout << mx;
	return 0;
}