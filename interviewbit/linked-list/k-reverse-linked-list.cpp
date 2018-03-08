/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    int c = 0;
    ListNode *temp = A;
    while(temp){
        temp=temp->next;
        c++;
    }
    int t = c/B;
    ListNode* next=A;
    int flag = 0;
    ListNode *tt = NULL;
    while(t--){
        int k = B;
        ListNode* prev = NULL;
        ListNode* current = next;
        while(k--){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        temp = prev;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = current;
        if(!flag){
            A = prev;
            flag = 1;
            tt = temp;
        }else{
            tt->next = prev;
            tt = temp;
        }
       // break;
    }
    return A;
}
