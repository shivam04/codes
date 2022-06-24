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
int Solution::lPalin(ListNode* A) {
    if(A==nullptr or A->next==nullptr)
        return 1;
    ListNode* sp = A;
    ListNode* fp = A;
    ListNode* prev = nullptr;
    while(fp and fp->next) {
        prev = sp;
        sp = sp->next;
        fp = fp->next->next;
    }
    if(fp!=nullptr) {
        sp = sp->next;
    }
    prev->next = nullptr;
    ListNode* fh = A;
    ListNode* sh = sp;
    reverseList(&sh);
    while(fh and sh and fh->val==sh->val) {
        fh = fh->next;
        sh = sh->next;
    }
    return (fh==nullptr and sh==nullptr);
}
