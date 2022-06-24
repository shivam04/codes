/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int common(ListNode *a, ListNode *b) {
    int count = 0;
    while(a and b and a->val==b->val) {
        a = a->next;
        b = b->next;
        count++;
    }
    return count;
}
int Solution::solve(ListNode* A) {
    ListNode* p = nullptr;
    ListNode* curr = A;
    int res = 1;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = p;
        res = max(res, 2*common(p, next)+1);
        res = max(res, 2*common(curr, next));
        p = curr;
        curr = next;
    }
    return res;
}
