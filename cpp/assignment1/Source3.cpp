
#include<iostream>
using namespace std;
class Complex
{
public:
	float real, img;
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(float num)
	{
		real = img = num;
	}
	Complex(float num1, float num2)
	{
		real = num1;
		img = num2;
	}
	friend void addcomplex(Complex, Complex);
	friend void mulcomplex(Complex, Complex);
};
void addcomplex(Complex c1, Complex c2)
{
	float sum_real = c1.real + c2.real;
	float sum_img = c1.img + c2.img;
	cout << "Sum of the Complex numbers is " << sum_real << "+i" << sum_img << "\n";
}
void mulcomplex(Complex c1, Complex c2)
{
	float mul_real = (c1.real*c2.real) - (c1.img*c2.img);
	float mul_img = (c1.img*c2.real) + (c2.img*c1.real);
	cout << mul_img;
	if (mul_img > 0)
	{
		cout << "Product of the complex numbers is " << mul_real << "+i" << mul_img;
	}
	else
		cout << "Product of the complex numbers is " << mul_real << mul_img << "i";

}
int main()
{
	float real1, img1, real2, img2;
	cout << "Enter real part of num1 ";
	cin >> real1;
	cout << "Enter imaginary part of num1 ";
	cin >> img1;
	cout << "Enter real part of num2 ";
	cin >> real2;
	cout << "Enter imaginary part of num2 ";
	cin >> img2;
	Complex c1(real1, img1), c2(real2, img2);
	addcomplex(c1, c2);
	mulcomplex(c1, c2);
	return 0;
}
