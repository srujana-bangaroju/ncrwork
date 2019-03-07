#include<iostream>
using namespace std;
void main()
{
	int n,i,j,temp;
	cout << "enter size ";
	cin >> n;
	int a[20];
	for (int k = 0; k < n; k++)
		cin>> a[k];

	for (i = 0; i < n - 1; i++)
	{
		
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
			
		}
		
	}
	for (int k1 = 0; k1 < n; k1++)
		cout << a[k1];
}
