#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
	string in;
	
string ans;
	int n;
	cin >> n;
	while (n--){
		cin >> in;
		for (int i = 0; i < in.length()-1; i++){
			int num = 0;
			for (int j = i+1; j < in.length(); j++){
				
				if (ans.empty() || find(ans.begin(), ans.end(), in[i]) - ans.begin() >= ans.size()){
					if (in[i] == in[j])num++;
					if (num>1){
						ans += (char)('0' + num);
					}
					ans += in[i];
				}
			}
		}
		cout << ans << endl;
	}
}