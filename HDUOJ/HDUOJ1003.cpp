#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    int tt = 1;
    cin >> t;
    int temp, max, now;
    int n;
    int m = t;
    while (t--){
        int s, e, ts;
        cin >> n >> temp;
        now = max = temp;
        s = 1;
        e = 1;
        ts = 1;
        for (int i = 2; i <= n; i++){
            cin >> temp;
            if (now + temp < temp){
                now = temp;
                ts = i;    //更新前缀
            }
            else {
                now += temp;
            }
            if (now>max){
                max = now;
                s = ts;
                e = i;   //更新后缀
            }
        }
        cout << "Case " << tt << ":" << endl << max << " " << s << " " << e << endl;
        if (tt++ < m)cout << endl;
    }
    return 0;
}
