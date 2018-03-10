/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));;
    temp->val = 0;
    temp->next = A;
    ListNode *c = A;
    ListNode *prev = temp;
    //int y = A->val;
    while(c){
        int flag = 0;
        while(c->next!=NULL and prev->next->val==c->next->val){
            c = c->next;
        }
        if(prev->next==c){
            prev = prev->next;
        }
        else{
            prev->next = c->next;
        }
        c = c->next;
    }
    A = temp->next;
    return A;
}
