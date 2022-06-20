/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* temp = A;
    while(temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
