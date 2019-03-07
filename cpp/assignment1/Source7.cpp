#include<iostream>
#include<cmath>
using namespace std;
class matrix
{
	int a[2][2];
public:
	void input()
	{
		cout << endl << "enter matrix values";
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> a[i][j];
			}
		}
	}
	friend void mul(matrix, matrix);
};
void mul(matrix m1, matrix m2)
{
	int c[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < 2; k++)
			{
				c[i][j] += m1.a[i][k] * m2.a[k][j];
			}
			cout << c[i][j] << " ";
		}
		cout << endl;
	}


}
void main()
{
	matrix x, y;
	x.input();
	y.input();
	mul(x, y);
}
