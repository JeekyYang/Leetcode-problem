ListNode* swap(ListNode *head) {
	if(nullptr == head || nullptr == head->next) return head;
	ListNode **first = &head, *second = head->next;
	while(second) {
		(*first)->next = second->next;
		second->next = *first;
		*first = second;
		first = &(second->next->next);
		if(*first == nullptr) break;
		second = (*first)->next;
	}
	return head;
}
