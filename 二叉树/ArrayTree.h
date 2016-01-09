#ifndef ArrayTree_
#define ArrayTree_
#include<algorithm>
#include<iostream>
#include"ComOperator.h"
#include<cmath>
using namespace std;
template<class T>
class ArrayTree:public ComOperator<T>{
protected:
	T *elem;
	int *flag;
	int maxn;
	int count;
public:
	ArrayTree();    //新加入的函数
	~ArrayTree();
	void buildRoot(T root);
	void addLeft(T current,T left);
	void addRight(T current,T right);
	T closetRoot(T a,T b);      //上机第7题


	//具体化继承函数
	virtual bool isEmpty();
	virtual T getRoot();
	virtual T getParent(T p);
	virtual T getLeft(T p);
	virtual T getRitht(T p);
	virtual void setElem(T p,T e);
	virtual void preOrder(T e);
	virtual void inOrder(T e);
	virtual void postOrder(T e);
	virtual void levelOrder();
	virtual void deleteLeft(T p);
    virtual void deleteRight(T p);


private:
	void extend();
	int find(T p);
	void dfsDelete(T p);

};
#endif


//上机第七题
template<class T>  
T ArrayTree<T>::closetRoot(T a,T b){
	int indexA=-1,indexB=-1;
	for(int i=0;i<maxn;i++){
		if(!flag[i])continue;
		if(elem[i]==a)indexA=i;
		if(elem[i]==b)indexB=i;
		if(indexA!=-1&&indexB!=-1)break;
	}

	if(!(indexA!=-1&&indexB!=-1)){
		cout<<a<<" and  "<<b<<" not all in this tree"<<endl;
		exit(0);
	}

	else if(getParent(a)==b)return b;
	else if(getParent(b)==a)return a;
	else {
		T ans=-1000;
		for(T ta=a;ta!=getRoot();ta=getParent(ta)){
			for(T tb=b;tb!=getRoot();tb=getParent(tb)){
				if(ta==tb){
					ans=ta;
					return ans;
				}
			}
		}
		return getRoot();
	}
}


template<class T>
int ArrayTree<T>::find(T p){
	for(int i=0;i<maxn;i++){
		if(elem[i]==p&&flag[i])return i;
	}

	return -1;
}

template<class T>
void ArrayTree<T>::dfsDelete(T p){
	flag[find(p)]=0;
	if(flag[find(getLeft(p))])dfsDelete(getLeft(p));
	if(flag[find(getRitht(p))])dfsDelete(getRitht(p));
}

template<class T>
ArrayTree<T>::ArrayTree(){
	maxn=1000;
	elem=new T[maxn];
	flag=new int[maxn];
	count=0;
	
}


template<class T>
ArrayTree<T>::~ArrayTree(){
	delete [] elem;
}

template<class T>
void ArrayTree<T>::buildRoot(T root){
	elem[0]=root;
	flag[0]=1;
	count++;
}


template<class T>
void ArrayTree<T>::addLeft(T current,T left){
	int i;
	for(i=0;i<maxn;i++)if(elem[i]==current&&flag[i])break;
		if(2*i+1>=maxn)extend();
	elem[2*i+1]=left;
	flag[2*i+1]=1;
	count++;
}

template<class T>
void ArrayTree<T>::addRight(T current, T right){
	int i;
	for(i=0;i<maxn;i++)if(elem[i]==current&&flag[i])break;
		if(2*i+1>=maxn)extend();
	elem[2*i+2]=right;
	flag[2*i+2]=1;
	count++;
}

template<class T>
void ArrayTree<T>::extend(){
	maxn*=2;
	T *temp=elem;
	elem=new T[maxn];
	copy(temp,temp+count,elem);
}

template<class T>
bool ArrayTree<T>::isEmpty(){
	if(count==0)return true;
	else return false;
}

template<class T>
T ArrayTree< T >::getRoot(){
	return elem[0];
}


template<class T>
T ArrayTree<T>::getParent(T p){
	if(p==getRoot()){
		cout<<p<<" is root"<<endl;
		exit(0);
	}
	int i;
	for(i=1;i<maxn;i++)if(elem[i]==p&&flag[i])break;
		if(i>=maxn){
			cout<<p<<" not in this tree"<<endl;
			exit(0);
		}
		if(i%2==0)return elem[(i-2)/2];
		else return elem[(i-1)/2];
}
	

template<class T>
T ArrayTree<T>:: getLeft(T p){
	int i;
	for(i=0;i<maxn;i++)if(elem[i]==p&&flag[i])break;
		if(i>=maxn){
			cout<<p<<" not in this tree"<<endl;
			exit(0);
		}

		if(i*2+1>=maxn||!flag[i*2+1]){
			cout<<p<<" have not left son"<<endl;
			exit(0);
		}

		else return elem[i*2+1];
}


template<class T>
T ArrayTree<T>::getRitht(T p){
	int i;
	for(i=0;i<maxn;i++)if(elem[i]==p&&flag[i])break;
		if(i>=maxn){
			cout<<p<<" not in this tree"<<endl;
			exit(0);
		}

		if(i*2+2>=maxn||!flag[i*2+2]){
			cout<<p<<" have not right son"<<endl;
			exit(0);
		}

		else return elem[i*2+2];
}


template<class T>
void ArrayTree<T>::setElem(T p,T e){
 	int i;
 	int add=1;
 	if(lower_bound(elem,elem+maxn,e)-elem>=0)add=0;
	for(i=0;i<maxn;i++){
		if(elem[i]==p&&flag[i]){
			if(add)elem[i]=e;
			break;
		}
	}
}


template<class T>
void ArrayTree<T>::deleteLeft(T p){
	T temp=getLeft(p);
	dfsDelete(temp);

}


template<class T>
void ArrayTree<T>::deleteRight(T p){
	T temp=getRitht(p);
	dfsDelete(temp);
}

template<class T>
void ArrayTree<T>::preOrder(T e){
	int index=find(e);
	if(index>=0){
	cout<<elem[index]<<" ";
	preOrder(elem[index*2+1]);
	preOrder(elem[index*2+2]);
	}
}


template<class T>
void ArrayTree<T>::inOrder(T e){
	int index=find(e);
	if(index>=0){
	inOrder(elem[index*2+1]);
	cout<<elem[index]<<" ";
	inOrder(elem[index*2+2]);
	}
}

template<class T>
void ArrayTree<T>::postOrder(T e){
	int index=find(e);
	if(index>=0){
	postOrder(elem[index*2+1]);
	postOrder(elem[index*2+2]);
	cout<<elem[index]<<" ";
	}
}

template<class T>
void ArrayTree<T>::levelOrder(){
	for(int i=0;i<maxn;i++){
		if(flag[i])cout<<elem[i]<<" ";
	}
}