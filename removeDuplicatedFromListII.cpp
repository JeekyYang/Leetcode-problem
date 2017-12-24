ListNode* remove(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode *pre = head, *cur = pre->next;
	if(pre->val != cur->val) {
		pre->next = remove(cur);
		return head;
	} else {
		while(cur && cur->val == pre->val) {
			cur = cur->next;
		}
		return remove(cur);
	}
}
