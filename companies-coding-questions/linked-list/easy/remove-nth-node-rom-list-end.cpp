/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len = 0;
    ListNode* current = A;
    while(current) {
        len++;
        current = current->next;
    }
    if(B>len) {
        B = len;
    }
    int k = len-B;
    current = A;
    ListNode* prev = nullptr;
    while(k--) {
        prev = current;
        current = current->next;
    }
    if(prev!=nullptr) {
        prev->next = current->next;
    } else {
        A = current->next;
    }
    delete(current);
    return A;
}
