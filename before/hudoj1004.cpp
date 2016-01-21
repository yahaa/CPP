#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int t;
	char color[1000][16];
	int maxc[1000];
	char ch[16];
	while (cin >> t&&t){
		getchar();
		for (int i = 0; i < t; i++){
			gets(color[i]);
			maxc[i] = 1;
		}
		for (int i = 0; i < t - 1; i++){
			for (int j = i + 1; j < t; j++){
				if (strcmp(color[i], color[j]) == 0)maxc[i]++;
			}
		}
			int ma= maxc[0];
			int mai = 0;
			for (int i = 0; i < t; i++){
				if (ma < maxc[i]){
					ma = maxc[i];
					mai = i;
				}
			}
			cout << color[mai] << endl;
	}
	return 0;
}