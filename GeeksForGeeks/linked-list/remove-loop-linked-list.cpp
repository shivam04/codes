void removeTheLoop(Node *head) {
    Node *fpt = head, *spt = head;
    while(spt and fpt and fpt->next) {
        fpt = fpt->next->next;
        spt = spt->next;
        if(fpt==spt)
            break;
    }
    if(!fpt)
        return;
    spt = head;
    Node *p;
    while(spt and fpt) {
        p = fpt;
        spt = spt->next;
        fpt = fpt->next;
        if(spt==fpt)
            break;
    }
    p->next = NULL;
}