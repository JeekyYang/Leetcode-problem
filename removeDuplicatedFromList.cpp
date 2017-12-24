ListNode* remove(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode *pre = head, *cur= pre->next;
	while(cur) {
		if(pre->val == cur->val) {
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
		} else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}
