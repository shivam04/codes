/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* current = A;
    while(current) {
        ListNode* start = current;
        while(current and current->val == start->val) {
            current = current->next;
        }
        start->next = current;
        if(!current)
            break;
    }
    return A;
}
