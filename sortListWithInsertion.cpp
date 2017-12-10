class ListNode {
	int val;
	ListNode *next;
	ListNode(int a):val(a), next(null){}
};

ListNode *sortListWithInsertion(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode *newHead = nullptr, **phead = &newHead;
	ListNode *cur = head;
	while(cur) {
		while((*phead) && cur->val > (*phead)->val) {
			phead = &((*phead)->next);
		}
		ListNode *tmp = cur->next;
		cur->next = *phead;
		*phead = cur;
		cur = tmp;
	}
	return newHead;
}
