#include<iostream>
using namespace std;
const int MAXN = 33;             //int   �������ݻ��ɶ����������32 λ��  ����ȡ32    

int C[MAXN][MAXN];
void init(){                  //��һ�˶�̬�滮    �ȰѺ���Ҫ����������ֵ�����   
	C[0][0] = 1;
	C[1][0] = 1;
	C[1][1]= 1;
	for (int i = 2; i < 33; i++){
		C[i][0] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		C[i][i] = 1;
	}
}
int bit[MAXN];
int calc(int n){         //����  С�ڵ���  n��    Round Numbers
	if (n <= 1)return 0;
	int len = 0;
	while (n>0){        //��n ת��Ϊ  �����ƵĹ���
		if (n & 1)bit[len++] = 1;         //�����Ƶ�������     �����λ�ϵ�����   1  ��ô��¼��  n�Ķ�������ֵ  
		else bit[len++] = 0;  
		n >>= 1;                    //����������λ����     
	}
	int ans = 0;
	for (int i = len - 1; i >0; i--){           //��һ������λ��  ��n�Ķ�����λ��С��   round  numbers
		if (i % 2 == 0)ans += (1 <<( i - 1)) / 2;
		else ans += ((1 << (i - 1)) - C[i - 1][(i - 1) / 2]) / 2;
	}


	int cnt1 = 0;                   //��һ�����ж�n�����ǲ���   round number 
	int cnt0 = 0;
	for (int i = 0; i < len; i++){
		if (bit[i] == 0)cnt0++;
		else cnt1++;
	}
	if (cnt0 >= cnt1)ans++;

	  

	cnt1 = 1;        //��һ�����ж�λ����nһ�������ǲ���    round number
	cnt0 = 0;
	for (int i = len - 2; i >= 0; i--){
		if (bit[i] == 1){
			for (int j = i; j >= 0 && j + cnt0 + 1 >= i - j + cnt1; j--)ans += C[i][j];
			cnt1++;
		}
		else cnt0++;
	}
	return ans;

}
int main(){
	init();
	int start, finish;
	while (cin >> start >> finish){
		cout << calc(finish) - calc(start-1) << endl;
	}
	return 0;
}
