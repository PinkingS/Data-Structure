#include <cstdio>
#include <list>
#include <iostream>
using namespace std;

int LastRemaining(int n, int m) {
	if(n < 1 || m < 1)
		return -1;

	list<int> numbers;
	for(int i = 0; i < n; ++i)
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();
	while(numbers.size() > 1) {
cout << "one go aroud" << endl;
		for(int i = 1; i < m; ++i) {
			++current;
			if(current == numbers.end())
				current = numbers.begin();
cout << *current << endl;
		}

		list<int>::iterator next = ++current;
		if(next == numbers.end())
			next = numbers.begin();
		--current;
cout << "--current : " << *current << endl;
		numbers.erase(current);
		current = next;
cout << "next : " << *current << endl;
	}	
	return *current;
}

int main() {
	int res = LastRemaining(5, 3);
	printf("%d\n",res);
	return 0;
}
