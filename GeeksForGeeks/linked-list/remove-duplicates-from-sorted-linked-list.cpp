/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};*/
Node *removeDuplicates(Node *root)
{
    Node* c = root;
    while(c and c->next){
        if(c->data==c->next->data){
            Node *n = c->next->next;
            free(c->next);
            c->next = n;
        }else{
            c =c->next;
        }
    }
    return root;
}