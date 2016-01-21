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

//bool isp(int n){
//	int i;
//	for ( i = 2; i < sqrt(n); i++){
//		if (n%i == 0)break;
//	}
//	if (i>sqrt(n))return 1;
//	else return 0;
//}
//int main(){
//	int t;
//	cin >> t;
//	int n;
//	while (t--){
//		int ansr, ansl, ans;
//		cin >> n;
//		int temp = sqrt(n);
//		if (temp <= 2){
//			for (int i =2;; i++){
//				if (isp(i)){
//					ans = i;
//					break;
//				}
//			}
//		}
//		else {
//			for (int i = temp;; i++){
//				if (isp(i)){
//					ansr = i;
//					break;
//				}
//			}
//			for (int i = temp;i>=2; i--){
//				if (isp(i)){
//					ansl = i;
//					break;
//				}
//			}
//			ans = abs(temp - ansr) > abs(temp - ansl) ? ansl : ansr;
//		}
//		cout << ans*ans << endl;
//	}
//	return 0;
//}
//
//


#include<iostream>
using namespace std;
int main(){
	long long  n;
	while (cin >> n){
		cout << n*(n + 1) / 2 << endl;
		cout << endl;
	}
	return 0;
}