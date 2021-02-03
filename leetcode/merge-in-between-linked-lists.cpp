/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;
        for (int i = 1; i < a; i++) {
            current = current->next;
        }
        ListNode* toRemove = current->next;
        current->next = list2;
        for (int i = 0; i < b - a + 1; i++) {
            toRemove = toRemove->next;
        }
        ListNode* lastNode = list2;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = toRemove;
        return list1;
    }
};