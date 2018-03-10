/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* root) {
     ListNode* c = root;
    while(c and c->next){
        if(c->val==c->next->val){
            ListNode *n = c->next->next;
            free(c->next);
            c->next = n;
        }else{
            c =c->next;
        }
    }
    return root;
}
