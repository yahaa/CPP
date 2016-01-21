#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iomanip>

using namespace std;
const int INF = 30010;
int per[INF], son[INF];


int find(int x)                                                                                                         //查找根节点
{
	int root = x;
	while (per[root] != root) root = per[root];                                                       //找到根节点时循环终止

	int i = x, j;
	while (i != root)                                                                                                        //路径压缩
	{
		j = per[i]; // 在改变上级之前用临时变量  j 记录下他的值 
		per[i] = root; //把上级改为根节点
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

			per[i] = i;                               //初始化时，每一个节点都是自己的父节点
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



