/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverseListUtil(ListNode** A, ListNode** B, ListNode **p, ListNode **head) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* temp = (*A);
    ListNode* bNext = (*B)->next;
    while(temp and temp!=bNext) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    (*A)->next = bNext;
    if((*p)!=nullptr) {
        (*p)->next = prev;
    } else {
        (*head) = prev;
    }
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(B==1)
        return A;
    ListNode* current = A;
    int cnt = 1;
    ListNode* start= A;
	ListNode* prevNext = nullptr;
    while(current) {
        current = current->next;
        cnt++;
        if(cnt==B) {
            reverseListUtil(&start, &current, &prevNext, &A);
            prevNext = start;
            start = start->next;
            current = start;
            cnt=1;
        }
    }
    return A;
}
