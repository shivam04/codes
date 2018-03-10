/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = 0;
    ListNode* p = A;
    while(p){
        n++;
        p = p->next;
    }
    int del = n-B;
    if(del<=0){
        A = A->next;
        return A;
    }
    p = A;
    for(int i=0;i<del-1;i++){
        p = p->next;
    }
    p->next = p->next->next;
    return A;
}
