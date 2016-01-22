#include<iostream>
using namespace std;
const double pi = 3.1415926;
int main(){
	double r, v1, v2;
	while (cin >> r >> v1 >> v2){
		double t = r / v1;
		if (t*v2 < pi*r)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}


