/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void insert(ListNode** h, ListNode** temp, ListNode *c) {
    if((*h)==nullptr) {
        (*h) = c;
        (*temp) = (*h);
    } else {
        (*temp)->next = c;
        (*temp) = (*temp)->next;
    }
}
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* fh = nullptr;
    ListNode* fht = fh;
    ListNode* sh = nullptr;
    ListNode* sht = sh;
    ListNode* curr = A;
    while(curr) {
        if(curr->val < B) {
            insert(&fh, &fht, curr);
        } else {
            insert(&sh, &sht, curr);
        }
        curr = curr->next;
    }
    if(sht!=nullptr)
        sht->next = nullptr;
    if(fh==nullptr)
        return sh;
    if(sh==nullptr)
        return fh;
    fht->next = sh;
    return fh;
}
