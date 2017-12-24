ListNode *rotate(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode *cur = head;
	int len = 1;
	while(cur->next) {
		cur = cur->next;
		len++;
	}
	cur->next = head;
	k = len-k%len;
	while(k--) cur = cur->next;
	head = cur->next;
	cur->next = nullptr;
	return head;
}
