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
    bool checkvalid(vector<ListNode*> &vec){
        for(int i = 0; i < vec.size(); ++i){
            if(vec[i]!= NULL) return true;
        }
        return false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
         * Use a array to store the current lists states.
         * Check the array every time to compare and insert the minimum value.
         */
        if(lists.size() == 0) return NULL;
        vector<ListNode*> vec = lists;
        ListNode ret(0);
        ListNode *p =  &ret;
        int min_val = 0x7fffffff;
        int pos;
        while(checkvalid(vec)){
            for(int i = 0; i < vec.size(); ++i){
                if(vec[i] != NULL){
                    if(vec[i]->val < min_val){
                        pos = i;
                        min_val = vec[i]->val;
                        /*
                         * The statement in while can be optimized, because the program doesn't 
                         * need to check vec array's minimum value every times.
                         */
                    }
                }
            }
            p -> next = vec[pos];
            p = p->next;
            vec[pos] = vec[pos]->next;
            min_val = 0x7fffffff;
        }
        return ret.next;
    }
};
/*--------------------2nd--------------------*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2){
        /*
         * Use Merge sort to divide and conquer.
         * When divide to 2 lists, merge the 2 lists.
         */
        ListNode ret(0);
        ListNode *p = &ret;
        while(list1&&list2){
            if(list1->val <= list2->val){
                p->next = list1;
                list1 = list1->next;
            }
            else{
                p -> next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if(list1){
            p -> next = list1;
        }
        if(list2){
            p -> next = list2;
        }
        return ret.next;
    }
    ListNode* merge(vector<ListNode*> &lists, int begin, int end){
        if(begin == end) 
            return lists[begin];
        if(begin + 1 == end)
            return mergeTwoLists(lists[begin], lists[end]);
        int mid = (begin+end)>>1;
        ListNode *l1 = merge(lists, begin, mid);
        ListNode *l2 = merge(lists, mid+1, end);
        return mergeTwoLists(l1,l2); 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return lists.size() == 0? NULL : merge(lists, 0, lists.size()-1);
    }
};

/*--------------------3rd--------------------*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /* Here is a tricky solution, add each lists's value to a new array,
         * then sort and insert to a new linked list and return it.
         */
        if(lists.size() == 0) return NULL;
        vector<int> vec;
        for(int i = 0; i < lists.size(); ++i){
            while(lists[i]!=NULL){
                vec.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(vec.begin(),vec.end());
        ListNode ret(0);
        ListNode *p = &ret;
        for(int i = 0; i < vec.size(); ++i){
            ListNode *tmp = new ListNode(vec[i]);
            p ->next = tmp;
            p = p->next;
        }
        return ret.next;
    }
};