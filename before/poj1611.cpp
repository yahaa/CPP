#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>

using namespace std;
const int INF = 30010;
int per[INF], son[INF];


int find(int x)                                                                                                         //���Ҹ��ڵ�
{
	int root = x;
	while (per[root] != root) root = per[root];                                                       //�ҵ����ڵ�ʱѭ����ֹ

	int i = x, j;
	while (i != root)                                                                                                        //·��ѹ��
	{
		j = per[i]; // �ڸı��ϼ�֮ǰ����ʱ����  j ��¼������ֵ 
		per[i] = root; //���ϼ���Ϊ���ڵ�
		i = j;
	}
	return root;
}
void join(int x, int y){
	int root1, root2;
	root1 = find(x);
	root2 = find(y);
	if (root1 != root2){
		per[root2] = root1;
		son[root1] += son[root2];
	}
}
int main(){
	int n, m, temp;
	while (cin>>n>>m&&n + m)
	{
		for (int i = 0; i<n; i++){ 

			per[i] = i;                               //��ʼ��ʱ��ÿһ���ڵ㶼���Լ��ĸ��ڵ�
			son[i] = 1;
		}

		while (m--){
			cin >> temp;
			int *stu = new int[temp];
			for (int j = 0; j<temp; j++){
				cin >> stu[j];
				if (j != 0)join(stu[j-1], stu[j]);
			}
			delete[]stu;
		}
		cout << son[find(0)] << endl;
	}
	return 0;
}



