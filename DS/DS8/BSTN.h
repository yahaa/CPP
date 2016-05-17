#ifndef bstn_
#define bstn_
template <class T>
struct BSTN{
	T data;
	int count;
	BSTN *lchild;
	BSTN *rchild;
	BSTN(T data){
		count=0;
		this->data=data;
		lchild=NULL;
		rchild=NULL;
	}
	BSTN(){
		count=0;
		lchild=NULL;
		rchild=NULL;
	}
};
#endif