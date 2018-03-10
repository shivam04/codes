/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    int k = C-B+1;
    if(k==1)
    return A;
    ListNode *t = A;
    int i=1;
    ListNode *pp = NULL;
    while(t){
        if(i==B){
            ListNode *tt = t;
            ListNode *prev = NULL;
            ListNode *next;
            ListNode *current = t;
            while(k--){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            if(pp!=NULL)
            {pp->next = prev;}
            tt->next = current;
            if(pp==NULL){
                A = prev;
            }
            break;
        }
        i++;
        pp = t;
        t = t->next;
    }
    return A;
}
