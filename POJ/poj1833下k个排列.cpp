#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1024;
int main(){
	int m;
	int test[MAXN];
	scanf("%d", &m);
	while (m--){
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)scanf("%d", &test[i]);
		while (k--){
			next_permutation(test, test + n);
		}
		printf("%d", test[0]);
		for (int i = 1; i < n; i++)printf(" %d", test[i]);
		printf("\n");
	}
	return 0;
}