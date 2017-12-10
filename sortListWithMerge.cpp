ListNode *sortWithMerge(ListNode *head) {
	if(head == nullptr || head->next == nullptr) return head;
	ListNode *fast = head, *slow = head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *head1 = sortWithMerge(head);
	ListNode *head2 = sortWithMerge(slow->next);
	return merge(head1, head2);
}
ListNode *merge(ListNode *head1, ListNode *head2) {
	if(nullptr == head1) return head2;
	if(nullptr == head2) return head1;

	ListNode *head = nullptr, **phead = &head;
	while(head1 && head2) {
		if(head1->val < head2->val) {
			*phead = head1;
			head1 = head1->next;
		} else {
			*phead = head2;
			head2 = head2->next;
		}
		phead = &((*phead)->next);
	}
	*phead = head1? head1:head2;
	return head;
}
