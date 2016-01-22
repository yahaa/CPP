
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
#include<iostream>
#include<cstring>
using namespace std;

double ans(double a[], int n, int k){
	double minn = 10000000000;
	double avareg;
	double t;
	double sum;
	for (int i = 0; i <=n - k; i++){
		t = 0;
		sum = 0;
		avareg = accumulate(a + i, a + i + k, t) / (double)k;
		//cout << avareg << endl;
		for (int j = i; j < i + k; j++){
			sum += (a[j] - avareg)*(a[j] - avareg);
		}
		minn = min(minn, sum /(double)k);
	}
	return minn;
}
int main(){
	double a[1001];
	int n, k;
	while (cin >> n >> k){
		for (int i = 0; i < n; i++)cin>> a[i];
			sort(a, a + n);
			printf("%.2f\n", ans(a, n, k));
	}
	return 0;
}