#include<iostream>           //¶¯Ì¬¹æ»®     
using namespace std;
int main(){
	int n;
	int a[55], b[55], c[55];
	a[0] = b[0] = c[0] = 0;
	a[1] = 1;
	b[1] = 0;
	c[1] = 0;
	a[2] = 1;
	b[2] = 0;
	c[2] = 0;
	a[3] = 1;
	b[3] = 1;
	c[3] = 0; 
	for (int i = 4; i <= 55; i++){
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1] - b[i - 2];
		c[i] = b[i - 1] + c[i - 1];
	}
	while (cin >> n){
		cout << a[n] + b[n] + c[n] << endl;
	}
	return 0;
}



