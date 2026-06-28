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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *iter = new ListNode();
        ListNode *sum = iter;
        int carry = 0;


        while(l1!=nullptr || l2!=nullptr || carry!=0){

            int val1 = l1!=nullptr?l1->val:0;
            int val2 = l2!=nullptr?l2->val:0;
            int newval = val1+val2+carry;

            carry = newval/10;
            newval = newval%10;

            if(l1!=nullptr)l1 = l1->next;
            else l1 = nullptr;
            if(l2!=nullptr)l2 = l2->next;
            else l2 = nullptr;

            iter->next = new ListNode(newval);
            iter = iter->next;
        } 
        return sum->next;
    }
};
