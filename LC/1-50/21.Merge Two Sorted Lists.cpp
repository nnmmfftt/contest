/*--------------------1st--------------------*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	/*
	 * To establish a list, and insert l1 and l2 respectively, 
	 * return the list at last.
	 *
	 */
    if(!l1 ) return l2;
    if(!l2 ) return l1;
    ListNode head_node(0);
    ListNode *ret = &head_node;
    while(l1 && l2){
        if(l1->val >= l2->val){
            ret->next = l2;
            l2 = l2->next;
        }
        else {
            ret->next = l1;
            l1 = l1->next;
        }
        ret = ret->next;
    }
    if(l1) ret -> next = l1;
    if(l2) ret -> next = l2;
    return head_node.next;
}
/*--------------------2nd--------------------*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	/*
	 * The compare option between l1 and l2 is O(min(l1,l2)), then connect the remaining
	 * list. Then use recurse to return the list from the last to the head. 
	 */
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1 -> val < l2 -> val){
        l1 ->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    else {
        l2 ->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}