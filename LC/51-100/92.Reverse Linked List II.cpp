struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    // find mth node and insert each node after n times
    // need n times operations
    if(n == m)
        return head;
    struct ListNode h = {0,head};
    struct ListNode *p = &h;
    struct ListNode *tail;
    for(int i = 1; i <=n; ++i){
        if (i < m)
            p = p->next;
        else if(i == m)
            tail = p->next;
        else{
            struct ListNode *tmp = tail->next;
            tail->next = tail->next->next;
            tmp->next = p->next;
            p->next = tmp;
        }
    }
return h.next;
}
