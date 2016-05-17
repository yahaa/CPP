#ifndef LN_
#define LN_
template <class T>
struct LN{
	T data;
	LN<T>*pri;
	LN<T>*next;
	LN(){
		pri=NULL;
		next=NULL;
	}
	LN(T e){
		data=e;
		pri=NULL;
		next=NULL;
	}
};
#endif