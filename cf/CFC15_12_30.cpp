#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
    char map[500][500];
	int query1[500][500];
	int query2[500][500];
int main(){
	
	int rows,clos;
	while(cin>>rows>>clos){
		memset(query1,0,sizeof(query1));
		memset(query2,0,sizeof(query2));
		for(int i=0;i<rows;i++)cin>>map[i];

				for(int i=0;i<rows;i++){
				     int temp=0;
			        for(int j=0;j<clos;j++){
				       if(map[i][j]=='.'&&map[i][j+1]=='.')query1[i][j]=temp++;
				         else query1[i][j]=temp;
			        }
			    }
			
			
			for(int j=0;j<clos;j++){
				int temp=0;
				for(int i=0;i<rows;i++){
					if(map[i][j]=='.'&&map[i+1][j]=='.')query2[i][j]=temp++;
					else query2[i][j]=temp;
				}
			}


                int queries;
                cin>>queries;
				while(queries--){
				int r1,l1,r2,l2;
				cin>>r1>>l1>>r2>>l2;
				r1--;
				l1--;
				r2--;
				l2--;
				int ans=0;
				for(int i=r1;i<=r2;i++)ans+=query1[i][l2]-query1[i][l1];
				for(int j=l1;j<=l2;j++)ans+=query2[r2][j]-query2[r1][j];
				cout<<ans<<endl;
			}
			
	}
}