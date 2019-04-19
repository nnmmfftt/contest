struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	
	if(l1 == NULL)return l2;
	if(l2 == NULL)return l1;
	struct ListNode *ret = (struct ListNode*)malloc
		(sizeof(struct ListNode));
	struct ListNode *p = ret;
	ret->val = NULL;
	int count = 0;
	while(l1||l2||count){
		int v1 = 0,v2 = 0;
		if(l1){
			v1 = l1->val;
			l1 = l1->next;
		}
		if(l2){
			v2 = l2->val;
			l2 = l2->next;
		}
		struct ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
		tmp->val = (v1+v2+count)%10;
		tmp->next = NULL;
		count = (v1+v2+count)>9?1:0;
		ret->next = tmp;
		ret = ret->next;

		}
	return p->next;
}
