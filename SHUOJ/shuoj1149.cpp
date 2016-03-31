#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;
    while(cin>>x2>>y2>>x3>>y3>>x4>>y4&&(x2||y2||x3||y3||x4||y4)){
        y1=x3+x4-y2;
        x1=y3+y4-x2;
        printf("Anna's won-loss record is %d-%d.\n",x1,y1);
    }
}