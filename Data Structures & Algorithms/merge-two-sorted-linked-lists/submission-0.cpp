/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l = list1, *r = list2, *node = new ListNode(0);
        ListNode *start = node;
        while(l && r){
            if(l->val<=r->val){
                node->next = l;
                l = l->next;
            }
            else{
                node->next = r;
                r = r->next;
            }
            node = node->next;
        }
        if(l) node->next = l;
        else node->next = r;

        return start->next;
    }
};
