#include<iostream>
using namespace std;
class sort
{
public:
	int n,a[20], low, high, pivot, i, j;
	void input()
	{
		cout << "enter size";
		cin >> n;
		cout << endl;
		low = 0;
		high = n - 1;
		cout << "enter " << n << "elements ";
		for (int p = 0; p < n; p++)
		{
			cin >> a[p];
		}
	}
	void quicksort(int a[],int low, int high)
	{

		pivot = a[low];

		i = low + 1;
		j = high;
		
		if (low < high)
		{
			while (1)
			{
				while (i <= high && a[i] < pivot)
					i++;
				while (a[j] > pivot)
					j--;
				if (i < j)
				{
					int temp;
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				else
					break;
			}
			int temp1 = a[low];
			a[low] = a[j];
			a[j] = temp1;
			quicksort(a,low, j - 1);
			quicksort(a,j + 1, high);
		}
	}
	void display()
	{
		cout << "elements are";
		for (int p = 0; p < n; p++)
		{
			cout << a[p];
		}
	}
};
void main()
{
	sort s;
	s.input();
	s.quicksort(s.a,s.low, s.high);
	s.display();

}