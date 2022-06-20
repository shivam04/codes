/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverseList(ListNode** A) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* temp = (*A);
    while(temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    (*A) = prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev = nullptr;
    while(fast and fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* fh = A;
    if(fast!=nullptr) {
        prev = slow;
        slow = slow->next;
    }
    prev->next = nullptr;
    ListNode* sh = slow;
    reverseList(&sh);

    while(fh and sh) {
        ListNode* temp = fh->next;
        ListNode* temp1 = sh->next;
        fh->next = sh;
        sh->next = temp;
        fh = temp;
        sh = temp1;
    }
    return A;
}
