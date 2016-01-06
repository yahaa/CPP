#include<iostream>
using namespace std;
int main(){
	int a[150];
	a[0]=0;
	a[1]=1;
	a[2]=1;
	for(int i=3;i<150;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	while(cin>>n&&n>=0){
		int i;
		for(i=0;i<150;i++){
			if(a[i]==n)
			break;
		}
		if(i<150)cout<<i<<endl;
		else cout<<"Not a Fibonacci number."<<endl;
	}
	return 0;
}