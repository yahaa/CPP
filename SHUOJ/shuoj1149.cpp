#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int x ,y,a1,b1,a2,b2,a3,b3;
	while(cin>>a1>>b1>>a2>>b2>>a3>>b3,a1||b1||a2||b2||a3||b3){
		x=(2*b1+b2+b3-a2-a3)/2;
		y=a1+b1-x;
		printf("Anna's won-loss record is %d-%d.\n",x,y);
	}
	return 0;
}
