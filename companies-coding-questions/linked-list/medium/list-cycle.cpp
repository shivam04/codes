/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* slow,*fast;
    slow = A;
    fast = A;
    int f = 0;
    while(slow and fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            f = 1;
            break;
        }
    }
    if(!f)
        return nullptr;
    slow = A;
    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
