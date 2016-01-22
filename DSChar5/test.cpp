#include "TriSparseMatrix.h"		

int main(void)
{

	try
	{
		const int rs = 7, cs = 6;
		TriSparseMatrix<int> a(rs, cs);
		int m[rs][cs] = {
			15, 0, 0, 22, 0, -5,
			0, 11, 3, 0, 0, 0,
			0, 0, 0, 6, 0, 0,
			0, 0, 0, 0, 0, 0,
			91, 0, 0, 0, 0, 0,
			0, 7, 0, 0, 0, 0,
			0, 0, 28, 0, 0, 0
		};
		int i, j, v;
		TriSparseMatrix<int> d(rs, cs);
		int ms[rs][cs] = {
			15, 0, 0, 22, 0, -5,
			0, 11, 3, 0, 0, 0,
			0, 0, 20, 6, 0, 0,
			0, 0, 0, 0, 0, 0,
			91, 0, 0, 30, 0, 0,
			0, 7, 0, 0, 0, 0,
			0, 0, 28, 0, 0, 0
		};
		for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			d.SetElem(i, j, ms[i][j]);

		for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			a.SetElem(i, j, m[i][j]);


		cout << "æÿ’Ûa:" << endl;
		for (i = 0; i < a.GetRows(); i++)	{
			for (j = 0; j < a.GetCols(); j++)	{
				\
					a.GetElem(i, j, v);
				cout << v << "\t";
			}
			cout << endl;
		}




		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
		TriSparseMatrix<int> b;

		TriSparseMatrix<int> c;
		c = a + d;                           //≤‚ ‘÷ÿ‘ÿ    +    
		for (i = 0; i < c.GetRows(); i++)	{
			for (j = 0; j < c.GetCols(); j++)	{
				c.GetElem(i, j, v);
				cout << v << "\t";
			}
			cout << endl;
		}


		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

		cout << endl << "æÿ’Ûaµƒ◊™÷√æÿ’Û:" << endl;
		//		
		a.FastTranspose(b);
		for (i = 0; i < b.GetRows(); i++)	{
			for (j = 0; j < b.GetCols(); j++)	{
				b.GetElem(i, j, v);
				cout << v << "\t";
			}
			cout << endl;
		}

	}
	catch (Error err)
	{
		err.Show();
	}

	system("PAUSE");
	return 0;
}


