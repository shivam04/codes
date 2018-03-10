/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverselist(ListNode **head)
{
    // Initialize prev and current pointers
    ListNode *prev = NULL, *curr = *head, *next;
 
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    ListNode *slow = A, *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head1 = A;
    ListNode *head2 = slow->next;
    slow->next = NULL;
    reverselist(&head2);
    A = (ListNode*)malloc(sizeof(ListNode));
    ListNode *curr = A;
    while (head1 || head2)
    {
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    return A->next;
}
