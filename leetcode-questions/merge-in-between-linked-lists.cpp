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
        ListNode* temp = list1;
        ListNode* prev;
        int cnt = 0;
        while(temp and cnt<a) {
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        ListNode* temp1 = prev;
        while(temp and cnt< b) {
            cnt++;
            temp = temp->next;
        }
        temp1->next = list2;
        while(list2 and list2->next) {
            list2 = list2->next;
        }
        list2->next = temp!=NULL ? temp->next : temp;
        return list1;
    }
};