#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int prime[40] = { 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 };
int main(){
	int a[21];
	int n;
	int t = 1;
	while (scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; i++){
			a[i] = i + 1;
		}
		printf("Case %d:\n", t++);
		while (next_permutation(a + 1, a + n)){
			int flag;
			for (int i = 0; i < n; i++){
				int sum = a[i] + a[(i + 1) % n];
				flag = prime[sum];
				if (flag == 0)break;
			}
				if (flag){
					printf("%d ", a[0]);
					for (int i = 1; i < n; i++){
						if (i != n - 1)printf("%d ", a[i]);
						else printf("%d\n", a[i]);
					}
				}
		}
		printf("\n");
	}
	return 0;
}





#include<stdio.h>       //����Ļ����㷨
#include<iostream>
#include<string.h>
using namespace std;
int prime[40] = { 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 };
int n;                          //���������Ϊn�����20������ֻҪ��40
int visited[21], a[21];
void dfs(int num){
	int i;
	if (num == n&&prime[a[num - 1] + a[0]]){                          //���������ˣ��������
		for (i = 0; i<num - 1; i++)printf("%d ", a[i]);
		printf("%d\n", a[num - 1]);
	}
	else{
		for (i = 2; i <= n; i++){
			if (visited[i] == 0){//�Ƿ��ù���
				if (prime[i + a[num - 1]]) {//�Ƿ�����ڵļ����������� 
					visited[i] = -1;//�����
					a[num  ] = i;//�Ž�����
					dfs(num+1); //�ݹ����
					visited[i] = 0; //��ȥ���
				//	cout << num << endl;
					//num--;
				}
			}
		}
	}
}
int main(){
	int num = 1;
	while (scanf("%d", &n) != EOF){
		printf("Case %d:\n", num++);
		memset(visited, 0, sizeof(visited));
		a[0] = 1;
		dfs(1);
		printf("\n");
	}
	return 0;
}