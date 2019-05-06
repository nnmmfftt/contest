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
    ListNode* reverseKGroup(ListNode* head, int k) {
    	/*
    	 * Push ListNode of length/k groups to a stack
    	 * and reconnect to form a new ListNode and return it.
    	 */  
        ListNode *rethead = new ListNode(0);
        ListNode *p = rethead;
        while(1){
            int count = k;
            stack<ListNode*> s;
            ListNode *tmp = head;
            while(count&&tmp!=NULL){
                s.push(tmp);
                tmp = tmp->next;
                count -=1;
            }
            if(count){
                p->next = head;
                break;
            }
            while(!s.empty()){
                p->next = s.top();
                p = p->next;
                s.pop();
            }
            p->next = tmp;
            head = tmp;
        }
        return rethead->next;
    }
};
class Solution {
public:
	ListNode *reverseall(ListNode *head){
		if(head == NULL|| head->next == NULL)return head;
		ListNode *newhead = reverseall(head->next);
		head->next->next = head;
		head->next = NULL;
		return newhead;
	}
	int get_len_node(ListNode *head){
		if(head !=NULL) {
			int count =1;
			while(head != NULL){
				head = head->next;
				count++;
			}
			return count;
		}
        else return 0;
	}
	ListNode *get_pth(ListNode *head, int p){
		while(head != NULL && p-1){
			p--;
			head = head->next;
		}return head;
	}
    ListNode* reverseKGroup(ListNode* head, int k) {
    	/*
    	 * Find each sublist and reverse it, then insert to original listnode.
    	 * The @reverseall function can be solve at many ways, here is a reverse
    	 * function.
    	 */
    	ListNode *rethead = new ListNode(0);
    	ListNode *p = rethead;
    	int len = get_len_node(head);
    	while(len  > 0){
    		if(len - k > 0){
                ListNode *last = get_pth(head,k);
                ListNode *tmp = last->next;
                last->next = NULL;
    			p->next = reverseall(head);
    			while(p->next!=NULL){
    				p = p->next;
    			}
    			p->next = tmp;
    			head = tmp;
                len -=k;
	    	}
	    	else{
	    		p->next = head;
                len -=k;
	    	}
    	}
    	return rethead->next;
    }
};