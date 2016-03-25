#include "Node.h"
#include <algorithm>
#include <iostream>
#ifndef UFO_
#define UFO_
template<class T>
class UFO{
protected:
	int size;
	Node<T> *sets;
	int find(T a);
public:
	UFO();
	UFO(T *a,int n);
	void unions(T a,T b);
	T getRoot(T a);

};
#endif


template<class T>
T UFO<T>::getRoot(T a){
	int index=find(a);
	return sets[index].date;
}

template<class T>
UFO<T>::UFO(){
	size=100;
	sets=new Node<T>[size];
	for(int i=0;i<size;i++){
		sets[i].date=i;
		sets[i].parent=-1;
	}
}


template<class T>
UFO<T>::UFO(T*a,int n){
	size=n;
	sets=new Node<T>[size];
	for(int i=0;i<size;i++){
		sets[i].date=a[i];
		sets[i].parent=-1;
	}

}

template<class T>
int UFO<T>::find(T a){
	int index=0;
	while(index<size&&sets[index].date!=a)index++;
	if(index==size)return -1;
	int parenta=a;
	while(sets[index].parent>-1)p=sets[p].parent;
	return p;
}

template<class T>
void UFO<T>::unions(T a,T b){
	int ra=find(a);
	int rb=find(b);
	if(ra!=rb&&ra!=-1&&rb!=-1){
		sets[ra].parent+=sets[rb].parent;
		sets[rb].parent=ra;
	}
}