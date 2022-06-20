/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int len = 0;
    ListNode* temp = A;
    while(temp != nullptr) {
        len++;
        temp = temp->next;
    }
    if(len==1)
        return nullptr;
    int k = len/2;
    temp = A;
    ListNode* prev = temp;
    while(k--) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete(temp);
    return A;
}
