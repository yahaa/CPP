#ifndef Link_
#define Link_
#include "LN.h"
template <class T>
class Link{
private:
	LN<T>*p;
	int sizes;
public:
	Link();
	void insert(T e);
	int size();
	void bsort();
	void print();
};
#endif
template<class T>
void  Link<T>::print(){
	LN<T>*t=p;
	while(t->next){
		std::cout<<t->next->data<<" ";
		t=t->next;
	}
}

template<class T>
Link<T>::Link(){
	p=new LN<T>;
	sizes=0;
}

template<class T>
void Link<T>::insert(T e){
	LN<T> *te;
	te=new LN<T>(e);
	LN<T> *t=p;
	while(t->next)t=t->next;
	t->next=te;
	te->pri=t;
	sizes++;
}

template<class T>
int  Link<T>::size(){
	return sizes;
}

template<class T>
void Link<T>::bsort(){
	int i=sizes;
	LN<T>*temp=NULL;
	while(i--){
		LN<T>*j=p->next;
		while(j){
			if(j->next&&(j->data >j->next->data)){
				temp=j->next;
				j->next=j->next->next;
				if(temp->next){
					temp->next->pri=j;
				}
				temp->pri=j->pri;
				j->pri->next=temp;
				j->pri=temp;
				temp->next=j;
			}
			else {
				j=j->next;
			}
		}
	}
}