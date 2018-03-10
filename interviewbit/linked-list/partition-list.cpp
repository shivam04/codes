/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *big=NULL,*qbig = NULL;
    ListNode *small = NULL,*qsmall=NULL;
    ListNode *temp = A;
    while(temp){
        if(temp->val>=B){
            if(big==NULL){
                ListNode *l = new ListNode(temp->val);
                big=l;
                qbig = big;
            }else{
                ListNode *l = new ListNode(temp->val);
                qbig->next = l;
                qbig = qbig->next;
            }
        }else{
            if(small==NULL){
                ListNode *l = new ListNode(temp->val);
                small=l;
                qsmall = small;
            }else{
                ListNode *l = new ListNode(temp->val);
                qsmall->next = l;
                qsmall = qsmall->next;
            }
        }
        temp = temp->next;
    }
    if(small==NULL)
    small=big;
    else
    qsmall->next = big;
    return small;
}
