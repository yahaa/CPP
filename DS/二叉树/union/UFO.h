#include "Node.h"
#include <algorithm>
#include <iostream>
#include <cmath>
#ifndef UFO_
#define UFO_
using namespace std;
template<class T>
class UFO{
protected:
	int size;
	Node<T> *sets;
	int find(T a);
public:
	UFO();
	~UFO();	
	UFO(T *a,int n);
	void unions1(T a,T b);//第一题    union(i,j)
	void unions2(T a,T b);//第二题    以节点高的为根合并   
	void unions3(T a,T b);//第三题    以节点数多的为根合并
	T getRoot(T a);
	Node<T>* getSet();
	int getSize();
	void print();

};
#endif


template<class T>
void UFO<T>::print(){
	for(int i=0;i<size;i++)
		cout<<i<<"    "<<sets[i].date<<"    "<<sets[i].parent<<endl;
}

template<class T>
Node<T>*UFO<T>::getSet(){
	return sets;
}

template<class T>
int UFO<T>::getSize(){
	return size;
}

template<class T>
UFO<T>::~UFO(){
	delete sets;
}

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
		sets[i].hight=1;
	}
}


template<class T>
UFO<T>::UFO(T*a,int n){
	size=n;
	sets=new Node<T>[size];
	for(int i=0;i<size;i++){
		sets[i].date=a[i];
		sets[i].parent=-1;
		sets[i].hight=1;
	}

}

template<class T>
int UFO<T>::find(T a){
	int index=0;
	while(index<size&&sets[index].date!=a)index++;
	if(index==size)return -1;
	while(sets[index].parent>-1)index=sets[index].parent;
	return index;
}

template<class T>
void UFO<T>::unions1(T a,T b){
	int ra=find(a);
	int rb=find(b);
	if(ra!=rb&&ra!=-1&&rb!=-1){
		sets[ra].parent+=sets[rb].parent;
		sets[rb].parent=ra;
	}
}


template<class T>
void UFO<T>::unions2(T a,T b){
	int ra=find(a);
	int rb=find(b);
	if(ra!=rb&&ra!=-1&&rb!=-1){
		if(sets[ra].hight>=sets[rb].hight){
			sets[ra].parent+=sets[rb].parent;
			sets[rb].parent=ra;
			if(sets[ra].hight==sets[rb].hight)sets[ra].hight++;
		}
		else{
			sets[rb].parent+=sets[ra].parent;
			sets[ra].parent=rb;
			if(sets[ra].hight==sets[rb].hight)sets[rb].hight++;
		}
		
	}
}

template<class T>
void UFO<T>::unions3(T a,T b){
	int ra=find(a);
	int rb=find(b);
	if(ra!=rb&&ra!=-1&&rb!=-1){
		if(abs(sets[ra].parent)>=abs(sets[rb].parent)){
			sets[ra].parent+=sets[rb].parent;
			sets[rb].parent=ra;
		}
		else{
			sets[rb].parent+=sets[ra].parent;
			sets[ra].parent=rb;
		}
	}
}

