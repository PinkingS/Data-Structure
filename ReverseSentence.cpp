#include <cstdio>
#include <cstring>

void Reverse(char* pBegin, char* pEnd) {
	if(pBegin == NULL || pEnd == NULL)
		return;

	while(pBegin < pEnd) {
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char *pData) {
	if(pData == NULL)
		return NULL;

	char* pBegin = pData;
	char* pEnd = pData;
	while(*pEnd != '\0')
		pEnd++;

	pEnd--;

	Reverse(pBegin, pEnd);

	pBegin = pEnd = pData;
	while(*pBegin != '\0') {
		if(*pBegin == ' ') {
			pBegin++;
			pEnd++;
		}
		else if(*pEnd == ' ' || *pEnd == '\0') {
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}
	return pData;
}

char* LeftRotateString(char* pStr, int n) {
	if(pStr == NULL)
		return NULL;

	int nLength = static_cast<int>(strlen(pStr));
	if(nLength > 0 && n > 0 && n < nLength) {
		char* pFirstStart = pStr;
		char* pFirstEnd = pStr + n - 1;
		char* pSecondStart = pStr + n;
		char* pSecondEnd = pStr + nLength - 1;

		Reverse(pFirstStart, pFirstEnd);
		Reverse(pSecondStart, pSecondEnd);
		Reverse(pFirstStart, pSecondEnd);
	}
	return pStr;
}

int main() {
	char a[] = "hello world ha hei";
	char* b = ReverseSentence(a);
	printf("%s\n",a);
	char c[] = "abcdefg";
	char* d = LeftRotateString(c, 3);
	printf("%s\n",d);
	return 0;
}
