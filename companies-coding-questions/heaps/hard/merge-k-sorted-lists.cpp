/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct MyCmp {
    bool operator()(ListNode *a, ListNode *b){
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;

    priority_queue<ListNode*, vector<ListNode*>, MyCmp> minH;

    for(ListNode* n: A) {
        minH.push(n);
    }

    while(!minH.empty()) {
        ListNode* minNode = minH.top();
        minH.pop();
        tail->next = minNode;
        if(minNode->next!=NULL) {
            minH.push(minNode->next);
        }
        tail = tail->next;
    }
    return head->next;
}
