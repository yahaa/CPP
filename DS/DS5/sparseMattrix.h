//œ° Ë
#include<iostream>
#include<algorithm>
#ifndef sparseMatrix_
#define sparseMatrix_
using namespace std;
template<class T>
class sparseMatrix{
private:
	triElem<T>*elem;
	int maxsize;
	int rows, cols;
	int total;
	bool cmp(triElem<T> a, triElem<T> b);
public:
	sparseMatrix(int rows,int cols);
	virtual ~sparseMatrix();
	int getRows();
	int getCols();
	int getTotalNoZero();
	void setIndexOf(int rows, int cols, const T value);
	sparseMatrix<T> operator  +(const sparseMatrix<T>ex);
	sparseMatrix<T>& operator =(sparseMatrix<T>ex);
	void transpose();
	void Qtranspose();
	triElem<T>*getP();
//	triElem<T>* operator  [](int i);           //
};
#endif
template<class T>
triElem<T>* sparseMatrix<T>::getP(){
	return elem;
}
template<class T>
sparseMatrix<T>::sparseMatrix(int rows,int cols){
	maxsize = rows*cols;
	this->cols = cols;
	this->rows = rows;
	elem = new triElem <T>[maxsize];
	total = 0;
}

template<class T>
sparseMatrix<T>::~sparseMatrix(){
	delete[]elem;
}

template<class T>
int sparseMatrix<T>::getCols(){
	return cols;
}

template<class T>
int sparseMatrix<T>::getRows(){
	return rows;
}

template<class T>
int sparseMatrix<T>::getTotalNoZero(){
	return total;
}

template<class T>
void sparseMatrix<T>::setIndexOf(int rows, int cols,const T value){
	elem[total].rows = rows;
	elem[total].cols = cols;
	elem[total++].value= value;
	//cout << elem[0].rows << " " << elem[0].cols << " " << elem[0].value << endl;
}

template<class T>
sparseMatrix<T> sparseMatrix<T>::operator+(const sparseMatrix<T>ex){
	if (ex.getCols() != cols || ex.getRows() != rows){
		cout << "Can't add" << endl;
		exit(0);
	}
	else {
		sparseMatrix temp = new sparseMatrix(ex.getRows(), ex.getCols());
		for (int i = 0; i < total;i++)
		for (int j = 0; j < ex.getTotalNoZero(); j++){
			if (ex.getP().[j].rows == elem[i].rows&&ex.getP().[j].cols == elem[i].cols)temp.setIndexOf(i, j, ex.getP().[j].value + elem[i].value);
			else {
				temp.setIndexOf(i, j, ex.getP().[j].value + elem[i].value);
				temp.setIndexOf(i, j, ex.getP().[j].value + elem[i].value);
			}
		}

	}
}

template<class T>
bool sparseMatrix<T>::cmp(triElem<T>a, triElem<T> b){
	return a.rows < b.rows;
}
