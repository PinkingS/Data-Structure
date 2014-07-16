#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

string printBinary(double num) {
	string res = "";
	while(num > 0) {
		if(res.length() > 32)
			return "ERROR";

		num *= 2;
		if(num >= 1) {
			res += "1";
			num -= 1;
		} else {
			res += "0";
		}
	}
	return res;
}

string printBinary(string val) {
	int pos = val.find('.', 0);
	int intpart = atoi(val.substr(0, pos).c_str());
	double decpart = atof(val.substr(pos, val.length()-pos).c_str());
	string intstr = "", decstr = "";
	while(intpart > 0) {
		if(intpart&1) intstr = "1" + intstr;
		else intstr = "0" + intstr;
		intpart >>= 1;
	}
	while(decpart > 0) {
		if(decstr.length() > 32) return "ERROR";
		decpart *= 2;
		if(decpart >= 1) {
			decstr += "1";
			decpart -= 1;
		}
		else
			decstr += "0";
	}
	return intstr + "." + decstr;
}

int main() {
	double num = 0.625;
	string res = printBinary(num);
	cout << res << endl;

	string val = "9.25";
	cout << printBinary(val) << endl;

	return 0;
}
