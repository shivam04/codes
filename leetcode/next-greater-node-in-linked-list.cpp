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
    void rev(ListNode** head) {
        ListNode *pre, *curr, *nex;
        pre = NULL;
        curr = *head;
        nex = curr->next;
        while (curr) {
            curr->next = pre;
            pre = curr;
            curr = nex;
            nex = (curr) ? curr->next : NULL;
        }
        *head = pre;
        
    }
    vector<int> nextLargerNodes(ListNode* head) {
        rev(&head);
        vector<int> ans;
        stack<int> st;
        while(head) {
            if (st.empty()) {
                st.push(head->val);
                ans.push_back(0);
            } else {
                while(!st.empty() && st.top() <= head->val) {
                    st.pop();
                }
                if(st.empty()) {
                    st.push(head->val);
                    ans.push_back(0);
                } else {
                    ans.push_back(st.top());
                    st.push(head->val);
                }
            }
            head = head->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};