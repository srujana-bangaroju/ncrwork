#include<iostream>
using namespace std;
class matrix
{
	int a[10][10];
	int size;
public:
	void matrixentry(int k,int l)
	{
		int i, j, k;
		cout << "enter matrix elements" << endl;
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < l; j++)
			{
				cin >> a[i][j];
			}
		}
	}
	void matrix_disp(int m,int n) 
	{
		int i, j, k;
		cout << "the elements are:" << endl;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout<< a[i][j]<<endl;
			}
		}
	}
	friend matrix vector_mul(matrix x, matrix y);
};
 matrix vector_mul(matrix x, matrix y,int k,int n)
{
	 int c[k][n] = {0};
	 int i, j;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n; j++)
		{
			c[i][j]+ = (a[i][j] * b[i][j]);
		}
	}
	return c;
}
int main()
{
	matrix a, b,res;
	int k, l;
	cout << "enter size of A matrix" << endl;
	cin >> k>>l;
	a.matrixentry(k,l);
	cout << "enter size of B matrix" << endl;
	cin >> m>>n;
	b.matrixentry(m,n);
	a.matrix_disp(k,l);
	b.matrix_disp(m,n);
	res = vector_mul(a, b);
	res.matrix_disp();
}