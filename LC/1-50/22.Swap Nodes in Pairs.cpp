/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*--------------------1st--------------------*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	/*
    	 * Tree pointer record pre, in, post node and reinsert.
    	 *
    	 *    tleft     tm    tr
    	 * head_node -> n1 -> n2 -> n3 -> NULL
    	 *
    	 *  tl->next = tr;
         *  tm->next = tr->next;
         *  tr->next = tm;
         *************************************
         *  Round 1:
         *
         *		step1:
         *
		 *    tleft     tm    tr
    	 * head_node -> n1 -> n2 -> n3 -> n4 -> NULL
    	 *
    	 *		step2:
    	 *
         *    tleft     tr    tm
    	 * head_node -> n2 -> n1 -> n3 -> n4 -> NULL
    	 *-------------------------------------
    	 *  Round 2:
    	 *		step1:
    	 *
    	 *                  tleft   tm    tr
    	 * head_node -> n2 -> n1 -> n3 -> n4 -> NULL
    	 *		step2:
		 *                  tleft   tr    tm
    	 * head_node -> n2 -> n1 -> n4 -> n3 -> NULL
    	 *
    	 *		
    	 */
        if(!head) return head;
        ListNode head_node(0);
        ListNode *p = &head_node;
        p ->next = head;
        ListNode *tl,*tm,*tr;
        tl = tm = tr = p;
        while(tm -> next && tm->next->next!=nullptr){
            tl = tm;
            tm = tm->next;
            tr = tm->next;
            tl->next = tr;
            tm->next = tr->next;
            tr->next = tm;
        	
        }
        return head_node.next;
    }
};

/*--------------------2nd--------------------*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	/*
    	 * For terminal condition :
    	 *		head->next->next does not exist
    	 *
    	 * The return val:
    	 *		sublist which already swap pairs
    	 *
    	 * In each recursion:
    	 *
    	 * 2 nodes ready to exchange, a sublist for recursion.
    	 *
    	 * 
    	 *  head     ret     recur(head->next->next)
    	 *   n1 ->   n2   ->         n3              -> n4 -> NULL
         *
         * The last recursion:
         *  head    ret     
    	 *   n1 ->   n2   -> n4 -> n3 -> NULL
    	 *-------------------------------------
    	 *  ret     head    
    	 *   n2 ->   n1   -> n4 -> n3 -> NULL
    	 *
    	 */
       if(!head || !head->next) return head;
       ListNode *ret = head->next;
       head->next = swapPairs(head->next->next);
       ret->next = head;
       return ret;
    }
};