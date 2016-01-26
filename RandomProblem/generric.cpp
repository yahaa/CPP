#include <iostream>
#include <string>
using namespace std;
template<class T>
void print(T a,T b){
	cout<<a+b<<endl;
}
int main(){
	int a=10;
	int b=1000;
	print(a,b);
	string c="jaklsdjflkasj";
	string d="jaklsdjflk;asjdfkl;sjadf";
	print(d,d);

}