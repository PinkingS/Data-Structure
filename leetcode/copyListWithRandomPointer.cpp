#include <iostream>
#include <map>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if(!head) return NULL;
	map<RandomListNode *, RandomListNode *> map;
	RandomListNode *old = head;
	RandomListNode dummy(0), *newList = &dummy;
	while(old) {
		RandomListNode *node = new RandomListNode(old->label);
		newList->next = node;
		newList = newList->next;
		map[old] = node;
		old = old->next;
	}
	newList = dummy.next;
	old = head;
	while(old) {
		newList->random = map[old->random];
		old = old->next;
		newList = newList->next;
	}
	return dummy.next;
}

RandomListNode *copyRandomList_2(RandomListNode *head) {
	if(!head) return NULL;
	RandomListNode *old = head;
	while(old) {
		RandomListNode *newNode = new RandomListNode(old->label);
		newNode->next = old->next;
		old->next = newNode;
		old = old->next->next;
	}
	old = head;
	while(old) {
		if(old->random)
			old->next->random = old->random->next;
		old = old->next->next;
	}
	RandomListNode dummy(0), *cur = &dummy;
	old = head;
	while(old) {
		cur->next = old->next;
		cur = cur->next;
		old->next = old->next->next;
		old = old->next;
	}
	return dummy.next;
}
