/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
    int len = 0;
    ListNode* temp = A;
    while(temp != nullptr) {
        len++;
        temp = temp->next;
    }
    if(len==1)
        return A->val;
    int k = len/2;
    temp = A;
    while(k--) {
        temp = temp->next;
    }
    return temp->val;
}
