#include<iostream>
using namespace std;            //¿¼ÊýÑ§   ÕÒÑ­»·    

int main(){
	int a, b, n;
	int f[50];
	f[1] = 1;
	f[2] = 1;
	while (cin >> a >> b>>n&&a&&b){
		int i;
		for (i = 3; i <50; i++){
			f[i] = (a*f[i - 1] + b*f[i - 2] ) % 7;

			if (f[i] == 1 && f[i -1] == 1)break;
			//cout << f[i] << " ";
		}
		n = n % (i - 2);
		f[0] = f[i-2];
		cout << f[n] << endl;
	}
	return 0;
}
