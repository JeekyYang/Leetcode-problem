ListNode *add(ListNode *l1, ListNode *l2) {
	if(l1 == nullptr) return l2;
	if(l2 == nullptr) return l1;

	ListNode *head = nullptr, **phead = &head;
	int carry = 0;
	while(l1 || l2) {
		int v1 = l1? l1->val:0;
		int v2 = l2? l2->val:0;
		int sum = v1+v2+carry;
		*phead = new ListNode(sum%10);
		carry = sum/10;
		l1 = l1? l1->next:nullptr;
		l2 = l2? l2->next:nullptr;
	}
	if(carry > 0) *phead = new ListNode(carry);
	return head;
}
