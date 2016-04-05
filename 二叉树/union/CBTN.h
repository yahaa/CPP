
#ifndef CBTN_
#define CBTN_
template<class T>
struct CBTN{
	T data;
	CBTN<T>*child;
	CBTN<T>*b;
	
};
#endif