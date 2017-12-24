ListNode *removeNthFromEnd(ListNode *head, int n) {
	if(nullptr == head) return head;
	ListNode *cur = head;
	while(--n) cur = cur->next;

	ListNode **phead = &head;
	while(cur->next) {
		cur = cur->next;
		phead = &((*phead)->next);
	}
	ListNode *t = *phead;
	*phead = t->next;
	delete t;
	return head;
}
