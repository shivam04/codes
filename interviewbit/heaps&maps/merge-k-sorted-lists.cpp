/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    priority_queue<int,vector<int>,greater<int>>pq;
    ListNode* n = NULL;
    ListNode* ans = NULL;
    int k=A.size();
    ListNode* a[k];
    for(int i=0;i<k;i++){
        pq.push(A[i]->val);
        a[i] = A[i];
    }
    
    int i;
    while(!pq.empty()){
        int  q = pq.top();
        pq.pop();
        for(i=0;i<k;i++){
            if(a[i]!=NULL and q==a[i]->val){
                break;
            }
        }
        if(n==NULL){
            n = new ListNode(q);
            ans = n;
        }else{
            ListNode* z = new ListNode(q);
            n->next = z;
            n = z;
        }
        a[i] = a[i]->next;
        if(a[i]!=NULL){
            pq.push(a[i]->val);
        }
    }
    return ans;
}
