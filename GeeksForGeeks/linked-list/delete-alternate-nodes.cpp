/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the binary tree
struct Node
{
	int data;
	struct Node *next;
};
*/
// Complete this function
void deleteAlt(struct Node *head){
    if(head==NULL or head->next==NULL)
    return ;
    Node *temp = head;
    while(temp and temp->next){
        Node *t = temp->next;
        temp->next = t->next;
        free(t);
        if(temp)
        temp = temp->next;
    }
}
