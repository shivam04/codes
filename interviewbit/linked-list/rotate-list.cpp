/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode *t = A;
    int n = 0;
    while(t){
        n++;
        t=t->next;
    }
    B = B%n;
    int k = n-B;
    if(k==0)
    return A;
    ListNode* prev = NULL;
    ListNode* next;
    ListNode* current = A;
    while(k--){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ListNode* first = prev;
    prev = NULL;
    ListNode *second = current;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    second = prev;
    t = first;
    while(t->next!=NULL){
        t = t->next;
    }
    t->next = second;
    prev = NULL;
    current = first;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
    return first;
}
