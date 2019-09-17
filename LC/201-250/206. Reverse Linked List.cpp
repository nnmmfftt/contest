/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* H){
        if (H == NULL || H->next == NULL)       
            return H;
        ListNode* newHead = reverseList(H->next); 
        H->next->next = H;                       
        H->next = NULL;                          
        return newHead;                          
	}

};

class Solution {
public:
	ListNode* reverseList(ListNode* H){
		ListNode* p = H;
		ListNode* ret = nulltpr;
		while(p!= nulltpr){
			ret = p;
			ret->next = ret;
			p = p->next;
		}
		return ret;
	}
}

