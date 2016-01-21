#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
struct point{
	double x, y;
};
point xy[100005];
int index[100005];
bool comparex(point a, point b){
	return a.x < b.x;
}
bool comparey(int a, int b){
	return xy[a].y < xy[b].y;
}

double dis(point a, point b){
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


double findans(int l, int r){
	if (l + 1 == r)return dis(xy[l], xy[r]);
	if (l + 2 == r)return min(dis(xy[r], xy[l]), min(dis(xy[l], xy[l + 1]), dis(xy[l + 1], xy[r])));
	int mid = (r + l) / 2;
	double ans = min(findans(l, mid), findans(mid + 1, r));
	int cnt = 0;
	for (int i = l; i <= r; i++){
		if (xy[i].x >= xy[mid].x - ans&&xy[i].x <= xy[mid].x + ans)index[cnt++] = i;

	}
	sort(index, index + cnt, comparey);
	for (int i = 0; i < cnt; i++)
	for (int j = i + 1; j < cnt; j++){
		if (xy[index[j]].y - xy[index[i]].y >= ans)break;
		else ans = min(dis(xy[index[j]], xy[index[i]]), ans);
	}
	return ans;
}
int main(){
	int n;
	while (scanf("%d",&n)&&n){
		for (int i = 0; i < n; i++)scanf("%lf%lf", &xy[i].x, &xy[i].y);
		sort(xy, xy + n, comparex);
		printf("%.2lf%\n", findans(0, n - 1) / 2);
	}
	return 0;
}

