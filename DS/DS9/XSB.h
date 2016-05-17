#ifndef XSB_
#define XSB_
template<class T>
class XSB{
private:
	T *a;
	T*sorta;
	int maxsize;
	int sizes;
public:
	XSB(int m);
	void insert(T *e,int s);
	void csort();
	void print();
};
#endif
template<class T>
XSB<T>::XSB(int m){
	maxsize=m;
	a=new T[maxsize];
	sorta=new T[maxsize];
}

template<class T>
void XSB<T>::insert(T *e,int s){
	sizes=s;
	for(int i=0;i<sizes;i++)a[i]=e[i];
}

template<class T>
void XSB<T>::csort(){
	for(int i=0;i<sizes;i++){
		int counts=0;
		for(int j=0;j<sizes;j++){
			if(a[j]<a[i])counts++;
		}
		sorta[counts]=a[i];
	}
}

template<class T>
void XSB<T>::print(){
	for(int i=0;i<sizes;i++)std::cout<<sorta[i]<<" ";
	std::cout<<std::endl;
}