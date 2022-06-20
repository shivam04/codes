/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void removeLoop(ListNode** s, ListNode** head) {
    ListNode* temp = (*s);
    ListNode* tempF = (*head);
    ListNode* prev = nullptr;
    while(tempF!=temp) {
        prev = temp;
        temp = temp->next;
        tempF = tempF->next;
    }
    prev->next = nullptr;
}

ListNode* Solution::solve(ListNode* A) {
    ListNode* slow,*fast;
    slow = A;
    fast = A;
    int f = 0;
    while(slow and fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            f = 1;
            removeLoop(&fast, &A);
            break;
        }
    }
    return A;
}
