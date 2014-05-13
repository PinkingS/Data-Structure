#include <iostream>
#include <cstring>
using namespace std;

void blankReplace(char* str) {
	if(str == NULL)
		return;
	int length = strlen(str);
	if(length == 0)
		return;
	
	// count the number of blanks
	int cnt = 0;
	for(int i = 0; i < length; ++i)
		if(str[i] == ' ')
			cnt++;

	// replace blanks from end to start
	int newLength = length + cnt * 2;
	str[newLength] = '\0';
	for(int i = length-1; i >= 0; --i) {
		if(str[i] == ' ') {
			str[newLength - 1] = '0';
			str[newLength - 2] = '2';
			str[newLength - 3] = '%';
			newLength -= 3;
		} else {
			str[newLength - 1] = str[i];
			newLength--;
		}
	}
	
}

char* blankReplace2(char* str) {
	if(str == NULL)
		return NULL;
	int length = strlen(str);
	
	//calculate the number of blanks
	int cnt = 0;
	for(int i = 0; i < length; ++i)
		if(str[i] == ' ')
			++cnt;

	char* newStr = new char[length + cnt * 2 + 1];
	if(newStr == NULL) {
		cout << "Out of space !" << endl;
		return NULL;
	}
	
	//replace blanks from start to end
	int p = 0;
	for(int i = 0; i < length; ++i) {
		if(str[i] == ' ') {
			newStr[p] = '%';
			newStr[p+1] = '2';
			newStr[p+2] = '0';
			p += 3;
		} else {
			newStr[p++] = str[i];
		}
	}
	newStr[p] = '\0';
	return newStr;
		
}

int main() {
	string str = "123456789";
	str[5] = '\0';
	cout << str << endl;
	const int len = 100;
	char a[len] = "hey you are good";
	cout << blankReplace2(a) << endl;
	blankReplace(a);
	cout << a << endl;
	
	return 0;
}
