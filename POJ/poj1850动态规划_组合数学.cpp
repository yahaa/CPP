#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 27;
int C[MAXN][MAXN];
void init(){
	C[0][0] = 1;
	for (int i = 2; i < MAXN; i++){
		C[i][0] = 1;
		for (int j = 1; j <=i; j++)C[i][j] = C[i - 1][j] +C[i - 1][j - 1];
	}
}
int main(){

	init();                       //��̬�滮   ������е������
	char ch[11];
	while (cin >> ch){
		int len = strlen(ch);;
		for (int i = 1; i < len; i++){                         //���������ַ����Ƿ��ǰ�˳�����    
			if (ch[i - 1] >= ch[i]){
				cout << 0 << endl;
				return 0;
			}
		}

		//��ⳤ��С��len����������
		int ans = 0;
		for (int i = 1; i < len; i++)ans += C[26][i];        //��ѧ�Ƶ��������ص�    C[M][N]=C[M-1][N-1]+C[M-2][N-1]+...........

		//��ⳤ��Ϊlen   ����������
		for (int i = 0; i < len; i++){
			char temp = (!i) ? 'a' : ch[i - 1] +1;
			while (temp <= ch[i] - 1){
				ans += C['z' - temp][len - 1 - i];
				temp++;
			}
		}

		cout << ++ans << endl;


	}
	return 0;
}