#include<iostream>
using namespace std;
void main()
{
	int a[20], n,i,j;
	cout << "enter size";
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		cin >> a[k];
	}
	for (i = 0; i < n; i++)
	{
		int loc = i; j = i + 1;
		while (j <= n-1)
		{
			if (a[j] < a[loc])
			{
				loc = j;
				j++;
			}
			else
				j++;
		
			
		}
		int temp;
		temp = a[i];
		a[i] = a[loc];
		a[loc] = temp;

	}
	for (int k = 0; k < n; k++)
	{
		cout<< a[k];
	}

}