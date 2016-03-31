
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=105;
char m[maxn][maxn];

int main(){
  string s, st;
   vector<pair<char, int> > key;
  while(cin>>s&&s!= "THEEND"){
    key.clear();
    memset(m,0,sizeof(m));
    cin >> st;
    for (int i=0; i<s.size();i++)key.push_back(make_pair(s[i], i));
    sort(key.begin(), key.end());
    int lens = st.size()/s.size();
    int i = 0;
    for (vector<pair<char, int> >::iterator it=key.begin(); it!=key.end();it++, i++){
      for (int j=0;j<lens;j++)m[it->second][j]=st[i*lens + j];
    }
    for (int i=0; i<lens;i++)
    for (int j=0; j<s.size();j++)cout<<m[j][i];
    cout << endl;
  }
  return 0;
}