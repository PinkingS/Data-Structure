#include <cstdio>
#include <iostream>
using namespace std;


void Permutation2(char* pStr, char* pBegin);

void Permutation(char* pStr) {
	if(pStr == NULL)
		return;
	Permutation2(pStr, pStr);
}

void Permutation2(char* pStr, char* pBegin) {
//cout << "pStr : " << pStr << endl;
//cout << "*pBegin : " << *pBegin << endl;
	if(*pBegin == '\0') {
		printf("%s\n",pStr);
		return;
	}
	for(char* pCh = pBegin; *pCh != '\0'; ++pCh) {
		char temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp; 

		Permutation2(pStr, pBegin+1);
		
		temp = *pCh;
		*pCh = *pBegin;
		*pBegin = temp;
	}
}

int main() {
	char str[] = "abc";
	char str2[] = "ef";
	//cout << *(++str) << endl;
	Permutation(str);
	Permutation(str2);
	return 0;
}
