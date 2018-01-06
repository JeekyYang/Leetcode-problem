class RandomListNode {
	int val;
	RandomListNode *next;
	RandomListNode *random;
	RandomListNode(int v): val(v), next(nullptr), random(nullptr){}
}

RandomListNode *copy(RandomListNode *head) {
	if(nullptr == head) return head;

	RandomListNode *cur = head;
	while(cur) {
		RandomListNode *t = new RandomListNode(cur->val);
		t->next = cur->next;
		cur->next = t;
		cur = t->next;
	}

	cur = head;
	while(cur) {
		if(cur->random) {
			cur->next->random = cur->random->next;
		}

		cur = cur->next->next;
	}
	
	RandomListNode *newHead = nullptr, **ph = &newHead;
	cur = head;
	while(cur) {
		*ph = cur->next;
		cur->next = cur->next->next;
		ph = &((*ph)->next);
		cur = cur->next;
	}
	return newHead;
}
