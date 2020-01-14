/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *fp=A;
    ListNode *sp=A;
    ListNode* p_sp;
    //cout<<fp->val<<" "<<sp->val<<"\n";
    while(sp and fp and fp->next){
        fp = fp->next->next;
        p_sp = sp;
        sp = sp->next;
       //cout<<fp->val<<" "<<sp->val<<"\n";
        if(fp==sp){
            ListNode* l1 = sp;
            ListNode* l2 = sp;
            int k = 1,i;
            while(l1->next!=l2){
                k++;
                l1=l1->next;
            }
            l1 = A;
            l2 = A;
            for(i=0;i<k;i++)
            l2=l2->next;
            while(l1!=l2){
                l1 = l1->next;
                l2 = l2->next;
            }
            return l1;
        }
    }
    return NULL;
}
