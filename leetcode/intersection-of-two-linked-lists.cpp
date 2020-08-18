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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB)
            return NULL;
        ListNode *p1 = headA, *p2 = headB;
        int a=0,b=0;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == NULL and !a) {
                a = 1;
                p1 = headB;
            }
            if(p2 == NULL and !b) {
                b = 1;
                p2 = headA;
            }
        }
        return p1;
    }
};