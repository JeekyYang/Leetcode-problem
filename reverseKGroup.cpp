ListNode* reverseKGroup(ListNode *head, int k) {
	if(nullptr == head || nullptr == head->next || k == 1) {
		return head;
	}

	ListNode *cur = head;
	int total = 
	while(cur->next) {
		total++;
		cur = cur->next;
	}

	if(total < k) return head;

	ListNode **phead = &head;
	while(total/k) {
		int cnt = k;
		ListNode *pre = *phead;
		while(--cnt) {
			cur = pre->next;
			pre->next = cur->next;
			cur->next = *phead;
			*phead = cur;
		}
		phead = &(pre->next);
		total = total-k;
	}
	return head;
}
