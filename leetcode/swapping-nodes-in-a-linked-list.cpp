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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* node1 = head;
        int c = 1;
        while(c<k) {
            node1 = node1->next;
            c++;
        }
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        ListNode* node2 = head;
        for (int i = 1; i < len - k + 1; i++) {
            node2 = node2->next;
        }
        swap(node1->val, node2->val);
        return head;
    }
};