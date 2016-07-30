#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void getNext(const string &pat, int *next){
	
	next[0]=-1;				             // 初始f[0]的值为-1
	int j = 0, k = -1;		
	while (j < pat.length() - 1){
		if (k == -1 || pat[k] == pat[j])next[++j]=++k;
		else k = next[k];
	}
		
}

int KMP_Find(const string &ob, const string &pat){
	int *next = new int[pat.length()];
	getNext(pat, next);
	
	int i=0,j=0;
	int n=ob.length(),m=pat.length();
	while(i < n && j < m&&n-i>=m){
		if (j==-1||pat[j] == ob[i]){       
			i++;    
			j++;
		}
		else j =next[j];
	}
	delete []next;
	if (j< pat.length())return -1;
	else return i-j;
}
int main(){
	string s;
	string t;
	cin >> s;
	while (1){
		cin >>t;
		int ans = KMP_Find(s, t);
		if (ans < 0)cout << "this is sssss" << endl;
		else cout << ans << endl;
	}
}



