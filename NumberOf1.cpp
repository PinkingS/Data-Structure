#include <cstdio>

int NumberOf1(int num) {
	int i = num;
	int count = 0;
	while(i > 0) {
		count += (i%2);
		i = i/2;
	}
	return count;
}

int NumberOf1_2(int num) {
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if(num & flag)
			++count;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_3(int num) {
	int count = 0;
	while(num) {
		++count;
		num = (num - 1) & num;
	}
	return count;
}

int main() {
	//int i = 9;
	int i = 0x7FFFFFFF;
	printf("%d\n",NumberOf1_3(i));
}
