#include<bits/stdc++.h>
using namespace std;
struct Node { 
    char a; 
    struct Node *next, *prev; 
};
void appendNode(struct Node** head, struct Node** tail, char x) { 
    struct Node* temp = new Node; 
    temp->a = x; 
    temp->prev = temp->next = NULL; 
  
    if (*head == NULL) { 
        *head = *tail = temp; 
        return; 
    } 
    (*tail)->next = temp; 
    temp->prev = *tail; 
    *tail = temp; 
}
void removeNode(struct Node** head, struct Node** tail, struct Node* x) {
    if(*head==NULL)
        return;
    if(*head == x) {
        *head = (*head)->next;
    } if(*tail == x) {
        *tail = (*tail)->prev;
    } if(x->next!=NULL) {
        x->next->prev = x->prev;
    } if(x->prev!=NULL) {
        x->prev->next = x->next;
    }
    delete(x);
 }
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    char a;
	    struct Node *mp[256];
	    int repeated[256]; 
	    for(int i=0;i<256;i++) {
	        mp[i] = NULL;
	        repeated[i] = 0;
	    }
	    
	    struct Node *head = NULL, *tail = NULL; 
	    for(int i=0;i<n;i++) {
	        cin>>a;
	        if(repeated[a-'a']==0) {
	            if(mp[a-'a']==NULL) {
	                appendNode(&head, &tail, a);
	                mp[a-'a'] = tail;
	            } else {
	                removeNode(&head, &tail, mp[a-'a']); 
	                repeated[a-'a'] = 1;
	                mp[a-'a'] = NULL;
	            }
 	        }
 	        if(head != NULL) {
 	            cout<<head->a<<" ";
 	        } else {
 	            cout<<"-1 ";
 	        }
	    }
	    cout<<"\n";
	}
	return 0;
}