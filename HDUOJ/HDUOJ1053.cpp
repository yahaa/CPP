#include <iostream>     //哈夫曼树   哈夫曼编码   
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int maxn=1010000;
struct node{    //树的节点  
	int data,dep;
	node *L,*R;
	node(){
		data=dep=0;
		L=R=NULL;
	}

	bool operator <(node a)const{
		return a.data<data;
	}
};

int ans;
int charnumber[maxn];
priority_queue<node>builqu;
queue<node>q;

void init(){  //初始化函数
	ans=0;
	memset(charnumber,0,sizeof(charnumber));
	while(!builqu.empty())builqu.pop();
	while(!q.empty())q.pop();
}

void HaffumanTree(){
	node *L,*R,*T;
	while(builqu.size()!=1){   //当优先队列里面只有一颗树的时候  说明 haffmanTree 已经建好了
		L=new node();
		R=new node();
		T=new node();
		*L=builqu.top();//buliqu 是优先队列  每一次都会最小的优先考虑
		builqu.pop();
		*R=builqu.top();
		builqu.pop();
		T->data=L->data+R->data;
		T->L=L;
		T->R=R;
		builqu.push(*T);
	}
}

void bfs(){  //通过bfs  求解 haffman编码后的长度
	node root=builqu.top();
	builqu.pop();
	q.push(root);  
    while(!q.empty()){  
        node x = q.front(); 
        q.pop();  
        if(x.L){  
            x.L->dep = x.dep + 1;  
            q.push(*(x.L));  
        }  
        if(x.R){  
            x.R->dep = x.dep + 1;  
            q.push(*(x.R));  
        } 
        if(!x.L && !x.R)ans += x.dep * x.data;  
    }  
}

void dfs(node *p, int dep){   //通过dfs 求解huffman 编码后的 长度
    if(!p->L && !p->R){  
        ans += p->data * dep;  
        return ;  
    }  
    if(p->L)dfs(p->L, dep+1);  
    if(p->R)dfs(p->R, dep+1);
}  


int main(){
	string s;  //输入的字符串
	while(getline(cin,s)&&s!="END"){
		init();
		int len=s.length();
		for(int i=0;i<len;i++)charnumber[s[i]]++;   //统计各个字符出现的频率

		for(int i=1;i<=100;i++){
			if(charnumber[i]){
				node temp;
				temp.data=charnumber[i];   //把各个字符串出现的频率放入优先队列里  
				builqu.push(temp);
			}
		}

		if(builqu.size()==1){   //特殊情况处理
			printf("%d %d 8.0\n",len*8,len);
			continue;
		}

		HaffumanTree();    //建立哈夫曼树
		//bfs();      //求解答案，可以 bfs  也可以  dfs
		node root = builqu.top(); 
		builqu.pop();  
        dfs(&root, 0);  //dfs 求解答案
		printf("%d %d %.1f\n",len*8,ans,len*8.0/ans);
	}
	return 0;
}
