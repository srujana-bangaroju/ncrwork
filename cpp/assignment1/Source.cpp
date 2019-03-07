//program to display student details
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>//for all string operations
#include<malloc.h>//for dynamic memory allocation
using namespace std;
class student
{
public:
	char * s;
	char *grade;
	int *marks;
};
class college
{
	student stu;
public:
	void set_data(const char name[], int marks1, int marks2, int marks3)
	{
		int len = strlen(name) + 1;
		stu.s = (char*)malloc(len * sizeof(char));
		strcpy(stu.s, name);
		stu.marks = (int *)malloc(3 * sizeof(int));//since 100 marks paper
		stu.grade = (char *)malloc(12 * sizeof(char));//for first,second or third class print
		stu.marks[0] = marks1;
		stu.marks[1] = marks2;
		stu.marks[2] = marks3;

	}
	float calculateaverage()
	{
		float avg = (stu.marks[0] + stu.marks[1] + stu.marks[2]) / (float)3;
		return avg;
	}
	void computegrade()
	{
		float avg = calculateaverage();
		if (avg > 60.0)
			strcpy(stu.grade, "first class");
		else if (avg >= 50.0 && avg < 60.0)
			strcpy(stu.grade, "second class");
		else if (avg >= 40.0 && avg < 50.0)
			strcpy(stu.grade, "third class");
		else
			strcpy(stu.grade, "FAIL");
	}
	void display()
	{
		cout << stu.s << endl;
		cout << "marks1:"<<stu.marks[0] << "marks2:" << stu.marks[1] << "marks3:" << stu.marks[2] << endl;
		cout << stu.grade << endl;
	}

};
int main()
{
	college c1;
	c1.set_data("name", 100, 20, 30);
	c1.computegrade();
	c1.display();
}
