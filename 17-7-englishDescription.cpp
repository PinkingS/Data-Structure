#include <iostream>
#include <string>

using namespace std;

string digits[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string bigs[] = {"", "Thousand", "Million"};

string numToString100(int number) {
	string str = "";

	if(number >= 100) {
		str += digits[number / 100 - 1] + " Hundred ";
		number %= 100;
	}

	if(number >= 11 && number <= 19) {
		return str + teens[number-11] + " ";
	} else if(number == 10 || number >= 20) {
		str += tens[number/10 - 1] + " ";
		number %= 10;
	}

	if(number >= 1 && number <= 9)
		str += digits[number-1] + " ";

	return str;
}

string numToString(int number) {
	if(number == 0)
		return "Zero";
	else if(number < 0)
		return "Negative " + numToString(-1 * number);

	int count = 0;
	string str = "";

	while(number > 0) {
		if(number % 1000 != 0) {
			str = numToString100(number % 1000) + bigs[count] + " " + str;
		}
		number /= 1000;
		++count;
	}
	return str;
}

int main() {
	int a = 34832932;
	cout << numToString(a) << endl;
	int b = 8937310;
	cout << numToString(b) << endl;
	return 0;
}
