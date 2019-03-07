#include<iostream>
using namespace std;
class sort
{
public:
	int a[20],n,low,high;

	sort()
	{
		low = 0;
		high = 0;
	}
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
	void mergesort(int low, int high)
	{
		if (low < high)
		{
			int mid;
			mid = (low + high) / 2;
			mergesort(low, mid);
			mergesort(mid + 1, high);
			merge(low, mid, high);
		}
	}
	void merge(int l1s, int l1e, int l2e)
	{
		int l2s = l1e + 1;
		int *l3, i, j, k = 0;
		l3 = new int[l2e - l1s + 1];
		i = l1s;
		j = l2s;
		while (i <= l1e&&j <= l2e)
		{
			if (a[i] > a[j])
				l3[k++] = a[j++];
			else
				l3[k++] = a[i++];
		}
		while (i <= l1e)
			l3[k++] = a[i++];
		while (j <= l2e)
		{
			l3[k++] = a[j++];
		}
		while (l2e >= l1s)
			a[l2e--] = l3[--k];
		delete l3;

	}
	void diplay()
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
	s.mergesort(s.low, s.high);
	s.diplay();


	
}