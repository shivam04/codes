/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int c1 = 0;
    ListNode *temp = A;
    while(temp){
        temp = temp->next;
        c1++;
    }
    int c2 = 0;
    temp = B;
    while(temp){
        temp = temp->next;
        c2++;
    }
    int extra = abs(c1-c2);
    if(c1>c2){
        //temp = A;
        for(int i=0;i<extra;i++){
            A = A->next;
        }
        while(A and B){
            if(A==B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
    }else if(c1<c2){
        for(int i=0;i<extra;i++){
            B = B->next;
        }
        while(A and B){
            if(A==B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
    }else{
        while(A and B){
            if(A==B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
    }
    return NULL;
}
