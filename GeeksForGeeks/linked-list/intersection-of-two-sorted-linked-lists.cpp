/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of the Linked list Node is as follows:
struct Node {
    int val;
    struct Node* next;
}; */
void intersection(Node **head1, Node **head2,Node **head3)
{
    Node *a = *head1;
    Node *b = *head2;
    while(a!=NULL and b!=NULL){
        if(a->val==b->val){
            Node *temp = (struct Node*) malloc(sizeof(struct Node));;
            temp->val=a->val;
            temp->next = NULL;
            if(*head3==NULL){
                *head3=temp;
            }else{
                struct Node *ptr = *head3;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next=temp;
            }
            a = a->next;
            b = b->next;
        }
        else if(a->val>b->val){
            b=b->next;
        }else{
            a=a->next;
        }
    }
}