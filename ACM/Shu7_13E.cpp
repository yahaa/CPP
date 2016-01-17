// #include<iostream>
// #include<string>
// #include<cstdio>
// using namespace std;
// int main(){
// 	string s;
// 	while(getline(cin,s)){
// 		int sum=0;
// 		for(int i=0;i<s.length();i++){
// 			if(s[i]==' ')cout<<endl;
// 			else if(isdigit(s[i]))sum+=s[i]-'0';
// 			else if(s[i]=='!'){
// 				cout<<endl;
// 				sum=0;
// 			}
// 			else {
// 				while(sum--){
// 					if(s[i]=='b')cout<<" ";
// 					else cout<<s[i];
// 				}
// 				sum=0;
// 			}
// 		}
// 		cout<<endl;
// 	}
// }


#include<stdio.h>
#include<string.h>
int main()
{
    char st[102][102],ch;
    int maxlen = 0,top = 0,lenth[102];
    while((gets(st[top])) != NULL)
    {
        if(strlen(st[top]) > maxlen)
            maxlen = strlen(st[top]);
        lenth[top] = strlen(st[top]);
        top++;
    }
    int i,j,k;
    for(i = 0;i < maxlen; i++)
    {
        for(j = top-1;j >= 0; --j)
        {
            if(lenth[j] > i)
                printf("%c",st[j][i]);
            else//其实所谓的细节就是在某一行的没有字符的位置，输出空格
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}


