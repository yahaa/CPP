
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#include<string>
#include<istream>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 27;
int C[MAXN][MAXN];
void init(){
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1] = 1;
	for (int i = 2; i < MAXN; i++){
		C[i][0] = 1;
		for (int j = 1; j < i; j++)C[i][j] = C[i - 1][j] +C[i - 1][j - 1];
		C[i][i] = 1;
	}
}
int main(){

	init();                       //��̬�滮   ������е������
	char ch[11];
	while (cin >> ch){
		int flag = 1;
		int ans = 0;
		int len = strlen(ch);;
		for (int i = 1; i < len; i++){                         //���������ַ����Ƿ��ǰ�˳�����    
			if (ch[i - 1] >= ch[i]){
				flag = 0;
				break;
			}
		}
		if (!flag)cout << ans<< endl; 
		//��ⳤ��С��len����������
		else {       //���еĵ�һ��һ��Ϊ   a
			for (int i = 1; i < len; i++)ans += C[26][i];        //��ѧ�Ƶ��������ص�  C[M][N]=C[M-1][N-1]+C[M-2][N]        C[M][N]=C[M-1][N-1]+C[M-2][N-1]+...........

			//��ⳤ��Ϊlen   ����������
			for (int i = 0; i < len; i++){
				char temp = (!i) ? 'a' : ch[i - 1] + 1;       //���i=0   temp='a'
				while (temp <= ch[i] - 1){                    //  �ж�temp   �Ƿ���С��   ch[i]      Ҫ������������  �ͱ���ʹ��   temp<ch[i]     ��temp<=ch[i]-1
					ans += C['z' - temp][len - 1 - i];
					temp++;
				}
			}

			cout << ++ans << endl;
		}
		
	}
	return 0;
}

