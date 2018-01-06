void reorder(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode *fast = head, *slow = head;
	while(fast->next &&fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *h2 = slow->next;
	slow->next = nullptr;
	h2 = reverse(h2);

	ListNode *cur = h2, *left = head;
	while(cur) {
		ListNode *tmp = cur->next;
		cur->next = left->next;
		left->next = cur;
		cur = tmp;
		left = left->next->next;
	}
}

ListNode *reverse(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	
	ListNode *pre = head, *cur = head->next;
	while(cur) {
		pre->next = cur->next;
		cur->next = head;
		head = cur;
		cur = pre->next;
	}
	return head;
}
