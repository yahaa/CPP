#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };    // Direction
int nA, A[100][100];

int beyondborder(int x, int y)
{
	return x<0 || x >= nA || y<0 || y >= nA || A[x][y];
}
void print()
{
	int i = 0, j = 0, k, d = 0;

	memset(A, 0, sizeof(int)* 10000);
	for (k = 1; k <= nA*nA; k++)
	{
		A[i][j] = k;
		if (beyondborder(i + dir[d][0], j + dir[d][1]))// change direction
			d = (d + 1) % 4;
		i += dir[d][0];
		j += dir[d][1];
	}
	for (i = 0; i<nA; i++)
	{
		for (j = 0; j<nA; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int main()
{
	while (scanf("%d", &nA))
		print();
}



