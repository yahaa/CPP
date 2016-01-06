#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
char ch[1001][1001];
int tchr[1001][1001];
int tchl[1001][1001];
int n, m;
 
int main(){
    int t;
    cin >> t;
 
    while (t--){
        memset(tchr, 0, sizeof(tchr));
        memset(tchl, 0, sizeof(tchl));
        int ans =0;
        scanf("%d%d",&n,&m);
        getchar();
        int tp;
        for (int i = 0; i < n; i++) {
            tp = 0;
            for (int j = 0; j < m; j++){
                scanf("%c",&ch[i][j]);
                if (ch[i][j] == '.'){
                    tp++;
                    tchr[i][j] = tp;
                    if (j == m - 1){
                        for (int k = j; (k >= 0 && ch[i][k] == '.'); k--){
                            tchr[i][k] = tp - 1;
                        }
                        tp = 0;
                    }
                }
                else {
                    for (int k = j-1; k >= 0 && ch[i][k]=='.'; k--)tchr[i][k] = tp-1;
                    tp = 0;
                }
             
            }
            getchar();
        }
          int i,j;
 
        for (j = 0; j < m; j++){
            tp = 0;
            for (i = 0; i < n; i++){
                if (ch[i][j] == '.'){
                    tp++;
                    tchl[i][j] = tp;
                    if (i == n - 1){
                        for (int k = i; (k >= 0 && ch[k][j] == '.'); k--)tchl[k][j] = tp - 1;
                        tp = 0;
                    }
                }
                else {
                    for (int k = i - 1; k >= 0 && ch[k][j] == '.'; k--)tchl[k][j] = tp - 1;
                    tp = 0;
                     
                }
            }
          
        }


        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                ans=max(ans,tchr[i][j]+tchl[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}