/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/
void sortList(Node *head)
{
    if (!head || !(head->next))
    return ;
    int one = 0,zero=0,two=0;
    Node *temp=head;
    while(temp){
        if(temp->data==0)
        zero++;
        else if(temp->data==1)
        one++;
        else
        two++;
        temp=temp->next;
    }
    temp = head;
    while(zero--){
        temp->data=0;
        temp=temp->next;
    }
    while(one--){
        temp->data=1;
        temp=temp->next;
    }
    while(two--){
        temp->data=2;
        temp=temp->next;
    }
}
