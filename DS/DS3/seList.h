#ifndef esqList_       //�����ʵ�ֹ������˺ܶ�ļ���    ȷ�е�˵��͵��     ���˱�׼�⺯�� 
#define esqList_
#include<iostream>
#include<ostream>
#include<algorithm>
#include<string>
using namespace std;
template<class T>
class esqList{
	private:           //���ݷ�װ
//protected:     
	void addSize();
	int length;
	int maxLength;
	T*elem;
public:
	
	esqList(int size = 10);
	esqList(T*v, int n, int size);
	esqList(esqList<T> &e);            
	virtual ~esqList(){ delete[]elem; }
	esqList<T> & operator =(esqList<T>&m);       //����   =
	void addElem(int i, const T&e);
	bool empty()const;
	int getSize()const;
	int getLength(){ return length; }
	int getMaxLength(){ return maxLength; }
	T getElemOfIndex(int i)const;
	void clear();      //���
	void sortList();        //�Ա�����
	void deleteElem(int i);
	int  findElem(const T&e)const;
	void push_back(T e);
	void deleteDifferent();                 //ȥ���ظ�
	void deleteZoneElem(int s, int t);           //ɾ��ָ�������Ԫ��
	void deleteElemOfIndex(int i);
	void reverse();            //����
	void pritn(ostream&out){
		for (int i = 0; i<length; i++){
			out <<elem[i] << " ";
		}
	}
	//friend ostream& operator <<(ostream & out, const esqList<T>& m);

};

#endif

template<class T>
void esqList<T>::reverse(){            //   ��ҵ������          ˳��������     �ռ临�Ӷ�   ΪO��1)             ʱ�临�Ӷ�   O��n/2)
	T temp;
	for (int i = 0, j = length - 1; i < j; i++, j--){
		temp = elem[i];
		elem[i] = elem[j];
		elem[j] = temp;
	}
}
template<class T>
void esqList<T>::deleteZoneElem(int s, int t){                 //ɾ��  ָ�����������              �ϻ�   2.4
	if (length == 0 || s >= t || t<0 && s>length - 1)cout << "error  index" << endl;             //������   ���в�Ϊ�գ�s<t������·�����  �������
	else {
		if (s <1 && t <= length){                        //���һ
			copy(elem + t, elem + length, elem);
			length -= t;
		}
		else if (s >=1 && t<=length){               //���  ��
			int operators = t - s+1;
			while (operators--){ 
				copy(elem + s , elem + length, elem + s-1);       //copy ������ʱ�临�Ӷ�    Ϊ   O��n)      �øú�������  for ѭ��  �򻯴���
				length--;
			}

		}
		else if (s >=1&& t >length)length = s-1;     //���   ��
		else if (s<=1&& t>=length)length = 0;             //���   ��
	}
}

template<class T>
void esqList<T>::deleteDifferent(){                //��˳����е��ظ�Ԫ��ɾ��           ��ҵ  1.3
	for (int i = 0; i < length-1; i++)
		for (int j = i+1; j < length; j++){
			if (elem[i] == elem[j]){
				if (elem[j + 1] != elem[j])copy(elem + i + 1, elem + length, elem + i);        //����STL�е�copy����   ȡ��forѭ��    ʹ�ô�����
				else {                 //copy  ������ʱ�� ���Ӷ�    Ϊ    O��n)
					copy(elem + i + 1, elem + length, elem + i);
					i--;
				}
				length--;
			}
		}
}
template<class T>
void esqList<T>::push_back(T e){
	if (length == maxLength)addSize();
	elem[length++] = e;
}
template <class T>
ostream & operator << (ostream&out, esqList<T> &m){
	m.pritn(out);
	return out;
}
template<class T>
esqList<T>& esqList<T>::operator =(esqList<T>&m)
{
	if (elem)delete[]elem;
	length = m.getLength();
	maxLength = m.getMaxLength();
	elem = new T[maxLength];
	copy(m.elem, m.elem + length, elem);
	return *this;
}

template<class T>
void esqList<T>::addSize(){
	esqList<T> temp = *this;
	if (elem)delete[] elem;
	maxLength *= 2;
	elem = new T[maxLength];
	copy(temp.elem, temp.elem+ length, elem);
	
}
template<class T>
esqList<T>::esqList(int size){
	maxLength = size;
	length = 0;
	elem = new T[maxLength];
}

template<class T>
esqList<T>::esqList(T*V, int n, int size){

	maxLength = size;
	elem = new T[maxLength];
	if (n < maxLength){
		copy(V, V + n, elem);
		length = n;
	}
	else{
		copy(V, V + size, elem);
		length = size;
	}
}

template <class T>
esqList<T>::esqList(esqList<T>&e) :elem(NULL){
	*this = e;
}



template<class T>
void esqList<T>::addElem(int t, const T &e){

	if (t<0 || t>length)cout << " the index is error" << endl;
	else if (length<maxLength){
		copy(elem + t, elem + length, elem + t + 1);
		elem[t] = e;
	}
	else if (length >= maxLength){
		addSize();
		copy(elem + t, elem + length, elem + t + 1);
		elem[t] = e;
	}
	length++;
}



template<class T>
bool esqList<T>::empty()const{
	return length<0;
}


template<class T>
int esqList<T>::getSize()const{
	return length;
}


template<class T>
T esqList<T>::getElemOfIndex(int i)const{
	if (i<0 || i>length)cout << " the index is error" << endl;
	else return elem[i];
}

template<class T>
void esqList<T>::clear(){
	length = 0;
}

template <class T>
void esqList<T>::sortList(){
	sort(elem, elem + length);
}


template<class T>
void esqList<T>::deleteElem(int i){
	i -= 1;
	if (i<0 || i>length)cout << "the index is error" << endl;
	else {
		copy(elem + i + 1, elem + length, elem + i);
		length--;
	}
}


template<class T>
int esqList<T>::findElem(const T&e)const{
	int i;
	for (i = 0; i<length; i++){
		if (elem[i] == e)break;
	}
	if (i < length)return i;
	else return -1;
}
