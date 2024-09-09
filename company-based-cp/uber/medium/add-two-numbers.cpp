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
    ListNode *getNext(ListNode* l) {
        return l != nullptr ? l->next : nullptr;
    }
    int getVal(ListNode* l) {
        return l != nullptr ? l->val : 0;
    }
    int getSum(ListNode* l1, ListNode* l2) {
        return getVal(l1) + getVal(l2);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(-1);
        ListNode* hSum = sum;
        int carry = 0;
        while(l1 or l2) {
            int curSum = getSum(l1, l2) + carry;
            l1 = getNext(l1);
            l2 = getNext(l2);
            carry = curSum/10;
            curSum %= 10;
            hSum->next = new ListNode(curSum);
            hSum = hSum->next;
        }
        
        if (carry > 0) {
            hSum->next = new ListNode(carry);
        }
        return sum->next;
    }
};