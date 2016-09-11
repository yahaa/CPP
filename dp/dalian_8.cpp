//============================================================================
// Name        : 棋盘覆盖.cpp
// Author      : coder
// Version     :
// Copyright   : www.acmerblog.com
// Description : A,B,C,D分别表示四种类型的骨牌.即
// 	 A  B   CC  DD
//	AA  BB  C    D
//============================================================================
#include <iostream>
using namespace std;
int N, X, Y; 
char map[1000][1000]; //棋盘数组
int dir[4][2] = { { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 0 } };
char pieces[4] = { 'A', 'B', 'C', 'D' };
int title = 0;


void set_piece(int style, int r, int c) {
	title++;
	for (int i = 0; i < 4; i++)
		if (i == style) { 
			for (int j = 0; j < 4; j++)
				if (i != j)
					map[r + dir[j][0]][c + dir[j][1]] = pieces[i];
		}
}


void chessBoard(int startR, int startC, int dr, int dc, int size) {
	if (size == 1)return;
	int s = size / 2;
	int rr = dr >= startR + s;
	int cc = dc >= startC + s;
	for (int i = 0; i < 4; i++) {
		if (dir[i][0] == rr && dir[i][1] == cc) {
			set_piece(i, startR + s - 1, startC + s - 1);

			for (int j = 0; j < 4; j++) {
				if (j == i)
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],dr, dc, s);
				else {
					chessBoard(startR + s * dir[j][0], startC + s * dir[j][1],
						startR + s - 1 + dir[j][0],
						startC + s - 1 + dir[j][1], s);
				}
			}
		}
	}
}

int main() {

	cout << "欢迎使用棋盘覆盖程序：" << endl;
	cout << "分别A,B,C,D代表4种不同方向的骨牌:" << endl << endl;
	cout << " 	 A    B     CC   DD" << endl;
	cout << "	AA    BB    C     D" << endl << endl;
	cout << "输入3个数，分别为棋盘大小N(小于1000)，残缺位置X,Y(1到N之间):" << endl;

	cin >> N >> X >> Y;
	//判断N是否为2的n次方
	if ((N & (N - 1)) || X > N || X < 1 || Y < 1 || Y > N) {
		cout << "输入不合法" << endl;
	} else {
		chessBoard(0, 0, X - 1, Y - 1, N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}