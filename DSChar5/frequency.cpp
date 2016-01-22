#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int a[128];
	char ch[10000];
	while (gets(ch)){
		memset(a, 0, sizeof(a));
		for (int i = 0; i<strlen(ch); i++)a[ch[i]]++;        //     ch[i]------->     65
		for (int i = 0; i<128; i++){
			if (a[i] != 0)printf("%c  %d\n", i, a[i]);
		}
	}
	return 0;
}