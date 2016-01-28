#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[1000];
	while (gets(a)){
		int sum = 0;
		for (int i = 0; i<strlen(a); i++)sum += a[i] - '0';
		if (sum == 0)break;
		while (sum> 9){
			int tsum = 0;
			int m = sum;
			while (m > 0){
				tsum += m % 10;
				m /= 10;
			}
		sum= tsum;
		}
		cout <<sum<< endl;
	}
	return 0;
}
