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

vector<int>ans;

int  KMP_Find(const string &ob, const string &pat){
	int *Next = new int[pat.length()];
	getNext(pat, Next);
	int i=0,k=-1;
	int nn=ob.length(),mm=pat.length();
	while(i<nn){
		while(i<nn&&k < mm){
			if (k==-1||pat[k] == ob[i]){       
				i++;    
				k++;
			}
			else k =Next[k];
		}	
		if (k< pat.length())return -1;
		else {
			ans.push_back(i-k);
			cout<<i<<" "<<k;
			k=-1;
			i=i-k;
			i++;
		}
	}
	delete []Next;
	return 1;
}
int main(){
	string s1,s2;
	cin>>s1;
	getchar();
	while(cin>>s2){
	KMP_Find(s1,s2);
	cout<<s1<<" "<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";

	}
}



