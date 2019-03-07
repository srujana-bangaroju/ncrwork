#include<iostream>

using namespace std;
class student
{
public:

	char *sname;
	char grade;
	float total;
	int sub1;
	int sub2;
	int sub3;
	
	void calgrade()
	{
		float avg;
		total = (float )(sub1 + sub2 + sub3);
		avg = total / 3;
		if (avg >= 60)
			grade = 'A';
		else if (avg < 60 && avg >= 50)
			grade = 'B';
		else
			grade = 'C';
		
	}
	friend ostream&  operator<<(ostream &cout, student s1);
	friend istream&  operator>>(ostream &cin, student &s1);

};


istream& operator >> (istream&cin, student &s1)
{
	cin >> s1.sname;
	cin >> s1.sub1;
	cin >> s1.sub2;
	cin >> s1.sub3;
	s1.calgrade();
	return (cin);
}
ostream& operator <<(ostream&cout, student s1)
{
	cout << "name is" << s1.sname << endl;
	cout << "sub1 marks" << s1.sub1 << endl;
	cout << "sub2 marks" << s1.sub2 << endl;
	cout << "sub3 marks" << s1.sub3 << endl;
	cout << "grade is" << s1.grade;
	return(cout);
}

void main()
{
	student s;
	cin >> s;
	cout << s;
}