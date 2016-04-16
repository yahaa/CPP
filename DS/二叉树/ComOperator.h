#ifndef ComOperator_
#define ComOperator_
using namespace std;
template<class T>
class ComOperator{
	virtual bool isEmpty()=0;
	virtual T getRoot()=0;
	virtual T getParent(T p)=0;
	virtual T getLeft(T p)=0;
	virtual T getRitht(T p)=0;
	virtual void setElem(T p,T e)=0;
	virtual void deleteLeft(T p)=0;
	virtual void deleteRight(T p)=0;
	virtual void preOrder(T e)=0;
	virtual void inOrder(T e)=0;
	virtual void postOrder(T e)=0;
	virtual void levelOrder()=0;	
};
#endif