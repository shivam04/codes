/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* head) {
    if(!head or !head->next)
    return head;
    ListNode* sp = head;
    ListNode* fp = head;
    ListNode *psp;
    while(fp and fp->next){
        fp = fp->next->next;;
        psp = sp;
        sp = sp->next;
    }
    psp->next=NULL;
    ListNode* current=sp;
    ListNode* next;
    ListNode* prev = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    ListNode* sh = prev;
    ListNode* fh = head;
    ListNode *pfh;
    while(fh){
        fh->val = sh->val - fh->val;
        pfh = fh;
        fh = fh->next;
        sh = sh->next;
    }
    current=prev;
    prev = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    sh = prev;
    pfh->next = sh;
    return head;
}
