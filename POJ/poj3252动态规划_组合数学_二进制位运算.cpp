#include<iostream>
using namespace std;
const int MAXN = 33;             //int   类型数据化成二进制最多是32 位，  最多可取32    

int C[MAXN][MAXN];
void init(){                  //跑一趟动态规划    先把后面要求的组合数的值求出来   
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
int calc(int n){         //计算  小于等于  n的    Round Numbers
	if (n <= 1)return 0;
	int len = 0;
	while (n>0){        //把n 转化为  二进制的过程
		if (n & 1)bit[len++] = 1;         //二进制的与运算     如果该位上的数是   1  那么记录下  n的二进制数值  
		else bit[len++] = 0;  
		n >>= 1;                    //二进制右移位运算     
	}
	int ans = 0;
	for (int i = len - 1; i >0; i--){           //这一步是求位数  比n的二进制位数小的   round  numbers
		if (i % 2 == 0)ans += (1 <<( i - 1)) / 2;
		else ans += ((1 << (i - 1)) - C[i - 1][(i - 1) / 2]) / 2;
	}


	int cnt1 = 0;                   //这一步是判断n本身是不是   round number 
	int cnt0 = 0;
	for (int i = 0; i < len; i++){
		if (bit[i] == 0)cnt0++;
		else cnt1++;
	}
	if (cnt0 >= cnt1)ans++;

	  

	cnt1 = 1;        //这一步是判断位数和n一样的数是不是    round number
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
