/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* ans = NULL;
    if(A->next==NULL){
        ans = A;
        return ans;
    }else{
        ans = reverseList(A->next);
        ListNode *temp = ans;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = A;
        A->next = NULL;
        return ans;
    }
}
