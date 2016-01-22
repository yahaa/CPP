#include<iostream>
using namespace std; 
int f(int n){
	int ans = 1;
	for (int i = 1; i <= n; i++)ans *= i;
	return ans;
}
int main(){
	cout << "n e" << endl;
	cout << "- -----------" << endl;
	cout << "0 1\n"
		<< "1 2\n"
		<< "2 2.5\n"
		<< "3 2.666666667\n"
		<< "4 2.708333333\n"
		<< "5 2.716666667\n"
		<< "6 2.718055556\n"
		<< "7 2.718253968\n"
		<< "8 2.718278770\n"
		<< "9 2.718281526" << endl;
	return 0;
}
