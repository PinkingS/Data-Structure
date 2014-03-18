#include <cstdio>

char FirstNotRepeatingChar(char* pStr) {
	if(pStr == NULL)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for(unsigned int i = 0; i < tableSize; ++i) {
		hashTable[i] = 0;
	}

	char* p = pStr;
	while((*p) != '\0') {
		hashTable[*p]++;
		p++;
	}
	
	p = pStr;
	while((*p) != '\0') {
		if(hashTable[*p] == 1)
			return *p;
		else
			p++;
	}
	return '\0';
}

int main(){
	char str[] = "abbbccaefaf";
	printf("%c\n",FirstNotRepeatingChar(str));
	return 0;
}
