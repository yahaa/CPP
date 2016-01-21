#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll m, n, x1, x2;
		cin >> m >> n;
		x1 = n;
		for (ll i = 1; i<m; i++)
		{
			cin >> n;
			if (x1<n)
			{
				x2 = x1;
				x1 = n;
				n = x2;
			}
			x1 = x1*n / gcd(x1, n);
		}
		cout << x1 << endl;
	}
	return 0;
}
/**************************************************************
Problem: 1780
User: 14122260
Language: C++
Result: Accepted
Time:0 ms
Memory:1560 kb
****************************************************************/