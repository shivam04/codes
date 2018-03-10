/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
};
*/
// Complete this function
// return true if two list are identical else return false
bool areIdentical(struct Node *head1, struct Node *head2)
{
    while(head1 and head2){
        if(head1->data!=head2->data)
        return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}