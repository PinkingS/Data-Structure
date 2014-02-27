#include <cstdio>
#include <cstring>

void ReplaceBlank(char str[], int length) {
	if(str == NULL || length <= 0)
		return;
	int actual_length = strlen(str);
	printf("%d\n",actual_length);
	for(int i = 0; str[i] != '\0'; ++i) {
		if(str[i] != ' ')
			continue;
		else {
			for(int j = actual_length + 2; j >= i; --j)
				str[j] = str[j-2];	
			actual_length = actual_length + 2;
			str[i] = '%';
			str[++i] = '2';
			str[++i] = '0';	
		}
	}	
}

void ReplaceBlank2(char str[], int length) {
	if(str == NULL || length <= 0)
		return;
	int actual_length = strlen(str);
	int blank_count = 0;
	for(int i = 0; str[i] != '\0'; ++i) {
		if(str[i] == ' ')
			++blank_count;
	}
	int new_length = actual_length + 2 * blank_count;
	int indexOfOriginal = actual_length;
	int indexOfNew = new_length;
	while(indexOfOriginal >= 0 && indexOfNew >= indexOfOriginal) {
		if(str[indexOfOriginal] != ' ') {
			str[indexOfNew--] = str[indexOfOriginal--];
		}
		else {
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
			indexOfOriginal--;
		}
	}
}

int main() {
	char str[50] = "An Apple a day keeps";
	ReplaceBlank2(str, 50);
	printf("%s\n",str);
	return 0;	
}
