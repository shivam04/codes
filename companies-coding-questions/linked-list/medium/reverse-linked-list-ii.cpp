/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void reverseList(ListNode** A, ListNode** B, ListNode **p, ListNode **head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* temp = (*A);
    ListNode* bNext = (*B)->next;
    while(temp and temp!=bNext) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    (*A)->next = bNext;
    if((*p)!=nullptr) {
        (*p)->next = prev;
    } else {
        (*head) = prev;
    }
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* first = nullptr;
    ListNode* second = nullptr;
    ListNode* curr = A;
    ListNode* prev = nullptr;
    B--;
    C--;
    C = C-B;
    while(curr and B--) {
        prev = curr;
        curr = curr->next;
    }
    first = curr;
    while(curr and C--) {
        curr = curr->next;
    }
    second = curr;
    if(first==second)
        return A;
    else if(first==nullptr or second==nullptr)
        return A;
    reverseList(&first, &second, &prev, &A);
    return A;
}
