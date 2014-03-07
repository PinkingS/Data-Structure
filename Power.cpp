#include <iostream>
using namespace std;

bool equal(double m, double n) {
	if((m-n) > -0.0000001 && (m-n) < 0.0000001)
		return true;
	else 
		return false;
}

double PowerWithUnsignedExp(double base, int exp) {
	double result = 1.0;
	for(int i = 1; i <= exp; ++i) {
		cout << "do once" << endl;
		result *= base;
	}
	return result;
}

double PowerWithUnsignedExp_2(double base, int exp) {
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	double result = PowerWithUnsignedExp(base, exp>>1);
	result *= result;
	if(exp & 0x1 == 1)
		result *= base;

	return result;	
}

double Power(double base, int exponent) {
	if(exponent == 0)
		return 1.0;
	if(equal(base, 0.0) && exponent < 0)
		return 0.0;

	int sign = 1;
	if(exponent < 0) {
		sign = -1;
		exponent = -exponent;
	}
	double result = PowerWithUnsignedExp_2(base, exponent);
	if(sign == -1)
		result = 1.0/result;
	
	return result;
}





int main() {
	cout << Power(5, 0) << endl;
	cout << Power(5, -2) << endl;
	cout << Power(2, 8) << endl;
	cout << Power(0, -2) << endl;
	return 0;
}
