/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* temp = NULL;
    ListNode *qq =  NULL;
    int c = 0;
    while(A and B){
        int p = (A->val+B->val+c);
        c = p/10;
        p = p%10;
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        q->val = p;
        q->next = NULL;
        if(temp==NULL){
            temp = q;
            qq = temp;
        }
        else{
            qq->next = q;
            qq = qq->next;
        }
        A = A->next;
        B = B->next;
    }
    while(A){
        int p = (A->val+c);
        c = p/10;
        p = p%10;
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        q->val = p;
        q->next = NULL;
        if(temp==NULL){
            temp = q;
            qq = temp;
        }
        else{
            qq->next = q;
            qq = qq->next;
        }
        A =A->next;
    }
    while(B){
        int p = (B->val+c);
        c = p/10;
        p = p%10;
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        q->val = p;
        q->next = NULL;
        if(temp==NULL){
            temp = q;
            qq = temp;
        }
        else{
            qq->next = q;
            qq = qq->next;
        }
        B =B->next;
    }
    if(c>=1){
        ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        q->val = c;
        q->next = NULL;
        if(temp==NULL){
            temp = q;
            qq = temp;
        }
        else{
            qq->next = q;
            qq = qq->next;
        }
    }
    return temp;
}
