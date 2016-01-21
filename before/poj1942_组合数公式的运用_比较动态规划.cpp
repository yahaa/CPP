
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#include<string>
#include<istream>
using namespace std;
//typedef long long ll;                       //动态规划问什么不行    
//const ll maxn =2500;
//const ll INF = 1000007;
//int C[maxn][maxn];
//void init(){
//	C[0][0] = 0;
//	for (int i = 1; i <=maxn; i++){
//		C[0][i] = 1;
//		C[i][0] = 1;
//	}
//	for (int i = 1; i <=maxn;i++)
//	for (int j = 1; j <=maxn; j++){
//		C[i][j] = C[i][j - 1] + C[i - 1][j];
//	}
//}

unsigned compute(unsigned n, unsigned m){
	double ans = 1;
	unsigned a = n + m;
	unsigned b = (n > m) ? m : n;      //
	while (b){
		ans *= (double)(a--) / (double)(b--);                       //组合数公式的另一种计算    算法的可行性
	}
	ans += 0.5;
	return (unsigned)ans;
}
int  main(){
	
	unsigned m, n;
	while (cin >> m >> n && (n != 0 || m != 0))
	{
		cout << compute(n, m) << endl;
	}
	return 0;
}


