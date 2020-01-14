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
Node *removeDuplicates(Node *root)
{
    unordered_map<int,int> mp;
    Node *p = root;
    Node *prev=NULL;
    while(p){
        if(mp[p->data]==1){
            prev->next = p->next;
            delete(p);
            //p = prev->next;
        }else{
            mp[p->data]=1;
            prev = p;
        }
        p = prev->next;
    }
    return root;
}