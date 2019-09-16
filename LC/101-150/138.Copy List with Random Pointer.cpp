/*--------------------1st--------------------*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // everything is hash
        unordered_map<Node*, Node*> m;
        Node* p = head;
        while(p){
            Node* node = new Node(p->val,NULL,NULL);
            m[p] = node;
            p = p->next;
        }
        p = head;
        while(p){
            // connect every node
            // the new node should be searched every times
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};

/*--------------------2nd--------------------*/
class Solution {
public:

    unordered_map<Node*, Node*>mp;
    Node *copyRandomList(Node *head)
    // hash recursion
    {
        if(!head) return NULL;
        if(mp[head]!=NULL) return mp[head];
        mp[head] = new Node(head->val);
        mp[head] -> next = copyRandomList(head->next);
        mp[head] -> random = copyRandomList(head->random);
        return mp[head];
    }
};

