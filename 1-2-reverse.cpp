#include <cstdio>

void reverse(char* str) {
	char *begin = str, *end = str;
	if(!str)
		return;
	while(*end) // find the last char of the string
		++end;
	--end;
	
	char tmp;
	while(begin < end) {
		tmp = *begin;
		*begin++ = *end;
		*end-- = tmp;
	}
}

int main() {
	char a[21] = "i'm holly hungry now";
	reverse(a);
	printf("%s\n", a);
	return 0;
}
