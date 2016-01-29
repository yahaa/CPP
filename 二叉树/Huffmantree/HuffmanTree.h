#ifndef HaffumanTree_
#define HaffumanTree_
#include <queue>
#include <algorithm>
#include <string>

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


class HaffmanTree{
	protected:
		const int maxn=1010000;
		string s;
		priority_queue<*node>bqu;    //建立哈夫曼树时用的优先队列
		queue<node>qu;
		charnumber[maxn];
		void statsChar();
		void preparePriorityQueue();
		void buildHaffmanTree();
	public:
		HaffmanTree(string ch);
};
#endif

HaffmanTree::HaffmanTree(string ch){
	s=ch;
	statsChar();
	preparePriorityQueue();
	buildHaffmanTree();
}

void HaffmanTree::statsChar(){
	int len=s.length();
	for(int i=0;i<len;i++)charnumber[s[i]]++;   //统计各个字符出现的频率
}


void HaffmanTree::preparePriorityQueue(){
	node *temp;
	for(int i=1;i<=100;i++){
			if(charnumber[i]){
				temp=new node();
				temp->data=charnumber[i];   //把各个字符串出现的频率放入优先队列里  
				bqu.push(temp);
			}
		}
}


void HaffmanTree::buildHaffmanTree(){
	node *L,*R,*T;
	while(bqu.size()!=1){   //当优先队列里面只有一颗树的时候  说明 haffmanTree 已经建好了
		L=new node();
		R=new node();
		T=new node();
		L=bqu.top();//buliqu 是优先队列  每一次都会最小的优先考虑
		bqu.pop();
		R=bqu.top();
		bqu.pop();
		T->data=L->data+R->data;
		T->L=L;
		T->R=R;
		builqu.push(T);
	}
}

