bool hasCircle(ListNode *head) {
	if(null == head || nullptr == head->next) return false;
	ListNode *fast = head, *slow=head;
	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) return true;
	}
	return false;
}
