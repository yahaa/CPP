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
#include <string>
#include <istream>
#include <iostream>
#include <cstring>
using namespace std;
const string BASE = "0123456789";
string  add(string a, string b){
	string ans;
	//int a[1000];
	
	int i = a.size()- 1;
	int j = b.size()- 1;
	int t = 0;
	for (; i >= 0 || j >= 0; i--, j--){
		int sum = 0;
		if (i >= 0)sum += a[i] - '0';
		if (j >= 0)sum += b[j] - '0';
		if (t >= 0)sum += t;
		ans += BASE[sum % 10];
		t = sum / 10;
	}
	if (t > 0)ans += BASE[t];
	reverse(ans.begin(), ans.end());
	return ans;
	
}
int main(){
	int n;
	cin >> n;
	string a, b;
	int t = 1;
	int m = n;
	while (n--){
		cin >> a >> b;
		printf("Case %d:\n", t);
		cout << a << " + " << b << " = " << add(a, b) << endl;     //1+2=3     Case:
		if(t++<m)cout << endl;
	}
	return 0;
}





