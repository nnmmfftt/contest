ListNode* removeNthFromEnd(ListNode* head, int n) {
    /*
     * Use 2 pointer walk and run,
     * run goes first for n steps, then run and walk go together.
     * The run and walk interval distance is n, the walk is n from the bottom.
     */ 
    if(head == nullptr || n == 0){
            return head;
        }
    struct ListNode *walk = head;
    struct ListNode *run = head;
    while(n--){
        run = run->next;
    }
    if(!run) return head->next;
    while(run->next){
        run = run->next;
        walk = walk->next;
    }
    walk->next = walk->next->next;
    return head;
}