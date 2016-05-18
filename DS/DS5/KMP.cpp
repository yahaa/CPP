#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


void getNext(const string &pat, int *Next){
	int j = 0, k = -1;             
	Next[0] = -1;                     
	while (j<pat.length() - 1){
		if (k == -1 || pat[k] == pat[j]){
			 j++;
			 k++;
			 if(pat[j]==pat[k])Next[j]=Next[k];
			 else Next[j]=k;
		}
		else k = Next[k];
	}
}
//NextÊý×é
int KMP_Find(const string &ob, const string &pat){
	int *Next = new int[pat.length()];
	getNext(pat, Next);
	for(int ii=0;ii<pat.length();ii++)cout<<Next[ii]<<" ";
	cout<<endl;
	cout<<ob.length()<<" "<<pat.length()<<endl;
	cout<<"-----"<<endl;
	int i=0,k=-1;
	int nn=ob.length(),mm=pat.length();
	while(i < nn && k < mm){
		if (k==-1||pat[k] == ob[i]){       
			i++;    
			k++;
		}
		else k =Next[k];
	}
	delete []Next;
	if (k< pat.length())return -1;
	else return i - k;
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



