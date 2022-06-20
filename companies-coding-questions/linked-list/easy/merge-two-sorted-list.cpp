/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void add(ListNode** current, ListNode** B, ListNode **head) {
    if((*head)==nullptr) {
        (*head) = new ListNode((*B)->val);
        (*current) = (*head);
    } else {
        (*current)->next = new ListNode((*B)->val);
        (*current) = (*current)->next;
    }
}
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* l1 = A;
    ListNode* l2 = B;
    ListNode* newHead = nullptr;
    ListNode* current = newHead;
    while(l1 and l2) {
        if(l1->val<l2->val) {
            add(&current, &l1, &newHead);
            l1 = l1->next;
        } else {
            add(&current, &l2, &newHead);
            l2 = l2->next;
        }
    }
    while(l1) {
        add(&current, &l1, &newHead);
        l1 = l1->next;
    }

    while(l2) {
        add(&current, &l2, &newHead);
        l2 = l2->next;
    }
    return newHead;
}
