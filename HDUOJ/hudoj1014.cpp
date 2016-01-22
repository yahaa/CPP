#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std; 
int visit[100000];
int main(){
	int step, mod;
	while (cin >> step >> mod){
		visit[0] = 1;
		memset(visit, 0, sizeof(visit));
		int f = 0;
		int se = 0;
		int i;
		for (i = 0; i < mod; i++){
			f = (f + step) % mod;
			if (visit[f] == 1)break;
			visit[f] = 1;
		}
		if (i == mod)printf("%10d%10d    Good Choice\n\n", step, mod);
	         else printf("%10d%10d    Bad Choice\n\n", step, mod);
	}
	return 0;
}