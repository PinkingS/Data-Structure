struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	ListNode *slow, *fast;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(!fast || !fast->next) return NULL;
	fast = head;
	while(fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}
