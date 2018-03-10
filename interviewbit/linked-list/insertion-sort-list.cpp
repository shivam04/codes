/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *temp = A;
    ListNode *result=NULL;
    ListNode *t;
    ListNode *l;
    while(temp){
        l = new ListNode(temp->val);
        if(result==NULL){
            result = l;
        }else{
            if(result->val>=temp->val){
                l->next = result;
                result = l;
            }else{
                t = result;
                while(t->next!=NULL and t->next->val<temp->val){
                    t =t->next;
                }
                l->next = t->next;
                t->next = l;
            }
        }
        temp = temp->next;
    }
    return result;
}