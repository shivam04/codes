/*
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
*/
ListNode* flatten(ListNode* a, ListNode *b) {
    ListNode* newHead = nullptr;
    ListNode* newHeadLast = newHead;
    while(a and b) {
        if(a->val<b->val) {
            if(newHead==nullptr) {
                newHead = newHeadLast = a;
            } else {
                newHeadLast->down = a;
                newHeadLast = newHeadLast->down;
            }
            a = a->down;
        } else {
            if(newHead==nullptr) {
                newHead = newHeadLast = b;
            } else {
                newHeadLast->down = b;
                newHeadLast = newHeadLast->down;
            }
            b = b->down;
        }
    } 
    while(a) {
        if(newHead==nullptr) {
            newHead = newHeadLast = a;
        } else {
            newHeadLast->down = a;
            newHeadLast = newHeadLast->down;
        }
        a = a->down;
    }
    while(b) {
        if(newHead==nullptr) {
            newHead = newHeadLast = b;
        } else {
            newHeadLast->down = b;
            newHeadLast = newHeadLast->down;
        }
        b= b->down;
    }
    return newHead;
}
ListNode* flatten (ListNode* root) {
    if(root == nullptr)
        return root;
    if(root->right==nullptr) {
        ListNode* ans = nullptr;
        ListNode* ansLast = nullptr;
        ListNode* curr = root;
        while(curr) {
            if(ans==nullptr) {
                ans = curr;
                ansLast = ans;
            }
            else {
                ansLast->down = curr;
                ansLast = ansLast->down;
            }
            curr = curr->down;

        }
        return ans;
    }
    ListNode* first = root;
    ListNode* second = root->right;
    ListNode* mergeList = nullptr;
    while(second) {
        mergeList = flatten(first, second);
        first = mergeList;
        second = second->right;
    }
    return mergeList;
}