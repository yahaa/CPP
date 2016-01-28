#include<iostream>
using namespace std;
int main(){
	int target;
	char  s[50];
	int ans = 0;
	int v1 = -1, w1 = -1, x1 = -1, y1 = -1, z1 = -1;
	char anss[5];
	while (cin >> target >> s&&target){
		for (int v = 26; v >= 1; v--)
		for (int w = 26; w >= 1; w--)
		for (int x = 26; x >= 1; x--)
		for (int y = 26; y >= 1; y--)
		for (int z = 26; z >= 1; z--){
			ans = pow(v, 1.0) - pow(w, 2.0) + pow(x, 3.0) - pow(y, 4.0) + pow(z, 5.0);
			if (ans == target){
				v1 = v;
				w1 = w;
				x1 = x;
				y1 = y;
				z1 = z;
				break;
			}

		}
		if (v1 > 0 && w1 > 0 && x1 > 0 && z1 > 0 && y1 > 0){
			anss[0] = v1 + 'A';
			anss[1] = w1 + 'A';
			anss[2] = x1 + 'A';
			anss[3] = y1 + 'A';
			anss[4] = z1 + 'A';
			cout << anss << endl;

		}
		else cout << "no solution" << endl;

	}
	return 0;
}