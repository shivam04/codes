/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
*/
Node *compute(Node *head)
{
    if(head==NULL or head->next==NULL)
    return head;
    Node* prev= NULL;
    Node* next;
    Node *current = head;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    Node* temp = head;
    int maxi = temp->data;
    Node *prevv = temp;
    temp = temp->next;
    while(temp){
        if(temp->data<maxi){
            Node *t = temp;
            prevv->next = temp->next;
            free(t);
            temp = prevv->next;
        }else{
            maxi = temp->data;
            prevv = temp;
            temp = temp->next;
        }
    }
    prev= NULL;
    next;
    current = head;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}