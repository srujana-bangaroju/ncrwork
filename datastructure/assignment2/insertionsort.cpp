#include<iostream>
using namespace std;
void main()
{
	int i, j, n,temp;
	cout << "enter size";
	cin >> n;
	int a[20];
	for (int k = 0; k < n; k++)
	{
		cin >> a[k];
	}
	for (i = 0; i <= n - 1; i++)
	{
		j = i - 1;
		temp = a[i];
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for (int k = 0; k < n; k++)
	{
		cout << a[k];
	}

}