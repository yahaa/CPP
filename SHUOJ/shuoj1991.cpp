#include <iostream>
#include <string>
using namespace std;
int main(){
	int a8,a7,a6,a5,a4,a3,a2,a1,a0;
	while(cin>>a8>>a7>>a6>>a5>>a4>>a3>>a2>>a1>>a0){
		if(a8==0&&a7==0&&a6==0&&a5==0&&a4==0&&a3==0&&a2==0&&a1==0&&a0==0)cout<<0<<endl;
		else {
		int c=0;
		string ans;
		if(a8!=0){
				c=1;
				if(a8==1)cout<<"x^8";
				else if(a8==-1)cout<<"-x^8";
				else cout<<a8<<"x^8";
		}
		if(a7!=0){
			if(c==0){
				c=1;
				if(a7==1)cout<<"x^7";
				else if(a7==-1)cout<<"-x^7";
				else cout<<a7<<"x^7";
			}
			else {
				if(a7>0){
				if(a7==1)cout<<" + "<<"x^7";
				else cout<<" + "<<a7<<"x^7";
			}
			else {
				if(a7==-1)cout<<" - "<<"x^7";
				else cout<<" - "<<-a7<<"x^7";
			}
			}
		}
		if(a6!=0){
			if(c==0){
			c=1;
				if(a6==1)cout<<"x^6";
				else if(a6==-1)cout<<"-x^6";
				else cout<<a6<<"x^6";
			}
			else {
				if(a6>0){
				if(a6==1)cout<<" + "<<"x^6";
				else cout<<" + "<<a6<<"x^6";
			}
			else {
				if(a6==-1)cout<<" - "<<"x^6";
				else cout<<" - "<<-a6<<"x^6";
			}
			}

		}

		if(a5!=0){
			if(c==0){
				c=1;
				if(a5==1)cout<<"x^5";
				else if(a5==-1)cout<<"-x^5";
				else cout<<a5<<"x^5";
			}
			else {
				if(a5>0){
				if(a5==1)cout<<" + "<<"x^5";
				else cout<<" + "<<a5<<"x^5";
			}
			else {
				if(a5==-1)cout<<" - "<<"x^5";
				else cout<<" - "<<-a5<<"x^5";
			}
			}

		}
	
		if(a4!=0){
			if(c==0){
				c=1;
				if(a4==1)cout<<"x^4";
				else if(a4==-1)cout<<"-x^4";
				else cout<<a4<<"x^4";
			}
			else {
				if(a4>0){
				if(a4==1)cout<<" + "<<"x^4";
				else cout<<" + "<<a4<<"x^4";
			}
			else {
				if(a4==-1)cout<<" - "<<"x^4";
				else cout<<" - "<<-a4<<"x^4";
			}
			}

		}

		if(a3!=0){
			if(c==0){
				c=1;
				if(a3==1)cout<<"x^3";
				else if(a3==-1)cout<<"-x^3";
				else cout<<a3<<"x^3";
			}
			else {
				if(a3>0){
				if(a3==1)cout<<" + "<<"x^3";
				else cout<<" + "<<a3<<"x^3";
			}
			else {
				if(a3==-1)cout<<" - "<<"x^3";
				else cout<<" - "<<-a3<<"x^3";
			}
			}

		}

		if(a2!=0){
			if(c==0){
				c=1;
				if(a2==1)cout<<"x^2";
				else if(a2==-1)cout<<"-x^2";
				else cout<<a2<<"x^2";
			}
			else {
				if(a2>0){
				if(a2==1)cout<<" + "<<"x^2";
				else cout<<" + "<<a2<<"x^2";
			}
			else {
				if(a2==-1)cout<<" - "<<"x^2";
				else cout<<" - "<<-a2<<"x^2";
			}
			}

		}

	
		if(a1!=0){
			if(c==0){
				c=1;
				if(a1==1)cout<<"x";
				else if(a1==-1)cout<<"-x";
				else cout<<a1<<"x";
			}
			else {
				if(a1>0){
				if(a1==1)cout<<" + "<<"x";
				else cout<<" + "<<a1<<"x";
			}
			else {
				if(a1==-1)cout<<" - "<<"x";
				else cout<<" - "<<-a1<<"x";
			}
			}

		}
		if(a0!=0){
			if(c==0){
				c=1;
				cout<<a0;
			}
			else{
				if(a0>0){
				cout<<" + "<<a0;
			}

			else{
				cout<<" - "<<-a0;
			}
			}
			
		}
		cout<<endl;
		}
	}
	return 0;
}