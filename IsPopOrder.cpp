#include <cstdio>
#include <stack>

bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
	if(pPush == NULL || pPop == NULL || nLength <= 0)
		return false;
	bool bPossible = false;
	std::stack<int> stackData;

	const int* pNextPush = pPush;
	const int* pNextPop = pPop;

	while(pNextPop - pPop < nLength) {
		while(stackData.empty() || stackData.top() != *pNextPop) {
			if(pNextPush - pPush == nLength)
				break;
			stackData.push(*pNextPush);
			pNextPush++;
		}
		if(stackData.top() != *pNextPop)
			break;
		
		stackData.pop();
		pNextPop++;

	}
	if(stackData.empty() && pNextPop - pPop == nLength)
		bPossible = true;

	return bPossible;
}

int main() {
	int push[] = {1, 2, 3, 4, 5};
	int pop[] = {4, 3, 5, 2, 1};
	printf("%d\n",IsPopOrder(push, pop, 5));
	return 0;
}
