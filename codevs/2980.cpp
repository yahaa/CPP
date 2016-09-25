/*************************************************************************
	> Author: yahaa
	> Mail: yuanzihua0@gmail.com 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <set>
#include <bitset>
#include <functional>
#include <iomanip>
#include <cstdlib>
#define FOR(x,y) for(int x=0;x<y;x++)
#define MS(a,x) memset(a,x,sizeof(a))
#define ROF(x,y) for(int x=y;x>=0;x--)
#define LFOR(i,x,y) for(int i=x;i<=y;i++)
#define ll long long
#define INF 0X3FFFF
using namespace std;

struct node{
	string s;
	int k;
};
node p[105];
bool cmp(node a,node b){
	if(a.k==b.k)return a.s<b.s;
	else return a.k>b.k;
}


int longestPalindromeSubSequence1(string str){
    int n=str.length();
    vector<vector<int> > dp(n,vector<int>(n));

    for(int j=0;j<n;j++){
        dp[j][j]=1;
        for(int i=j-1;i>=0;i--){
            if(str[i]==str[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}


// int main()
// {
//     string s;
//     int length;
//     while(cin>>s){
//         length=longestPalindromeSubSequence2(s);
//         cout<<length<<endl;
//     }
//     return 0;
// }

int main(){
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		int k=longestPalindromeSubSequence1(s);
		p[i].s=s;
		p[i].k=k;
	}

	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)cout<<p[i].s<<endl;
	return 0;
}