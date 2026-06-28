/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *,Node*> oldtonew;
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        if(oldtonew.find(head)!=oldtonew.end()) return oldtonew[head];

        Node *copy = new Node(head->val);
        oldtonew[head] = copy;
        copy->next  = copyRandomList(head->next);
        copy->random = oldtonew[head->random];
        return copy;
    }
};
