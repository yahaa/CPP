#ifndef Heap_
#define Heap_
#include <algorithm>
template<class T>
class Heap{
	private:
		T *date;
		int maxn;
		int n;
		void swap(int x,int y);
		int siftDown(int i);
	public:
		Heap(T*a,int n);
		bool isHeap();

};
#endif

template<class T>
Heap<T>::Heap(T*a,int n){
	this->n=n;
	maxn=1000;
	date=new T[maxn];
	for(int i=0;i<n;i++)date[i+1]=a[i];
}

template<class T>
void Heap<T>::swap(int x,int y){
	int t;
	t=date[x];
	date[x]=date[y];
	date[y]=t;
}

template<class T>
int Heap<T>::siftDown(int i){
	int ans=0;
	int t,flag=0;
	while(i*2<=n&&flag==0){
		if(date[i]>date[i*2+1])t=i*2;
		else t=i;
		if(i*2+1<=n){
			if(date[t]>date[i*2+1])t=i*2+1;
		}

		if(t!=i){
			swap(t,i);
			ans++;
			i=t;
		}
		else flag=1;
	}
	return ans;
}


template<class T>
bool Heap<T>::isHeap(){
	int ans=0;
	for(int i=n/2;i>=1;i--){
		ans+=siftDown(i);
	}
	if(ans)return false;
	else return true;
}