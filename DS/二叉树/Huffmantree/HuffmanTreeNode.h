#ifndef node_
#define node_
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
#endif