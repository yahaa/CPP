#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	char s[100000], temp[100000];
	string a;
	string b;
	while (gets(s)!=NULL){
	//	puts(s);
		a.clear();
		b.clear();
		int n = strlen(s);
		int j;
		for (int i = 0; i < n; i++){
			j = i;
			while (isalpha(s[j])||isdigit(s[j])){
				j++;
			}
			strncpy(temp,s+i,j-i);
			temp[j-i] = '\0';
			i = j;
			int falg = 0;
			for (int k = 0; k < strlen(temp); k++){
				if (isalpha(temp[k])){
					falg = 1;
					break;
				}
				if (temp[0] && strlen(temp) != 1)falg = 1;
			}
			if (!falg){
				for (int k = 0; k < strlen(temp); k++)
				{
					if (k != strlen(temp) - 1)a += temp[k];
					else {
						a += temp[k]; 
						a += ',';
					}
				}
			}
			else {
				for (int k = 0; k < strlen(temp); k++)
				if (k != strlen(temp) - 1)b += temp[k];
				else {
					b += temp[k];
					b += ',';
					
				}
			}
		
		}
		/*cout << a << endl;
		cout << b << endl;*/
		cout << "\"" << a[0];
		for (int i = 1; i < a.size() - 2; i++)cout << a[i];
		cout << a[a.size() - 2] << "\"" << endl;
		cout << "\"" << b[0];
		for (int i = 1; i < b.size() - 2; i++)cout << b[i];
		cout << b[b.size() - 2] << "\"" << endl;
	}
}