#include<iostream>
#include<cmath>
using namespace std; 
const double PI = 3.1415926535;
int main(){
	int t;
	cin >> t; 
	while (t--){
		double n;
		cin >> n;
		double ans = (0.5*log(2 * PI*n) + n*log(n) - n) / log(10);
		cout << (int)(ans + 1) << endl;
	}
	return 0;
}