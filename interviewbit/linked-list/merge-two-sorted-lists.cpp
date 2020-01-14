/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL)
    return B;
    if(B==NULL)
    return A;
    ListNode *temp = NULL;
    if(A->val<B->val){
        temp = A;
        A = A->next;
    }else{
        temp = B;
        B = B->next;
    }
    ListNode *pp=temp;
    while(A and B){
        if(A->val<B->val){
            pp->next = A;
            A = A->next;
            //B = B->next;
        }else{
            pp->next = B;
            B = B->next;
        }
        pp=pp->next;
    }
    while(A){
        pp->next = A;
        pp =pp->next;
        A = A->next;
    }
    while(B){
        pp->next = B;
        pp =pp->next;
        B = B->next;
    }
    return temp;
}
