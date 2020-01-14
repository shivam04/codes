/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/
int detectloop(Node *list)
{
   Node* l = list;
   Node* r = list;
   while(l and r and r->next){
       l = l->next;
       r = r->next->next;
       if(l==r){
           return 1;
       }
   }
   return 0;
   
}