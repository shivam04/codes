/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Pairwise swap a linked list
  The input list will have at least one element  
  node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void pairWiseSwap(struct node *head)
{
    struct node *l = head;
    while(l!=NULL and l->next!=NULL){
        swap(&l->data,&l->next->data);
        l = l->next->next;
    }
}