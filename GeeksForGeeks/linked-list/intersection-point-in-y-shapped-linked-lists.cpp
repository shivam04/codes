int intersectPoint(Node* head1, Node* head2) {
    Node*temp;
    int c1 = 0, c2 = 0;
    temp = head1;
    while(temp) {
        temp = temp->next;
        c1++;
    }
    temp = head2;
    while(temp) {
        temp = temp->next;
        c2++;
    }
    Node *temp1 = head1, *temp2 = head2;
    if(c1 > c2) {
        int d = c1-c2;
        while(temp1 and d--) {
            temp1 = temp1->next;
        }
        while(temp1 != NULL and temp2 != NULL and temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp2->data;
    } else {
        int d = c2-c1;
        //cout<<d<<"\n";
        while(temp2 and d--) {
            temp2 = temp2->next;
        }
        //cout<<temp2->data<<"\n";
        while(temp1 != NULL and temp2 != NULL and temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp2->data;
    }
}