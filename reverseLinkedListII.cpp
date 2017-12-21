ListNode* reverseBetween(ListNode *head, int m, int n) {
	if(nullptr == head || nullptr == head->next || m == n) return head;
	ListNode **phead = &head;
	for(int i = 1; i < m; i++) {
		phead = &((*phead)->next);
	}
	ListNode *pre = *phead, *cur = pre->next;
	for(int i = 1; i < m-n; i++) {
		pre->next = cur->next;
		cur->next = *phead;
		*phead = cur;
		cur = pre->next;
	}
	return head;
}
