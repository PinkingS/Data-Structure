#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
};

ListNode* findLoopStart(ListNode *head) {
	if(!head) return NULL;

	ListNode *slow = head, *fast = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) break;
	}

	if(!fast || !fast->next) return NULL; // not a loop
	slow = head;
	while(fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

map<ListNode*, bool> hash;
ListNode *findLoopStart2(ListNode *head) {
	while(head) {
		if(hash[head]) return head;
		else {
			hash[head] = true;
			head = head->next;
		}
	}
	return NULL;
}
