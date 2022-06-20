#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* head = nullptr;

void insert_node(int position, int value) {
    position--;
    ListNode* node = new ListNode(value);
    if(head==nullptr) {
        if(position != 0)
            return;
        else
            head= node;
        return;
    }
    if(head !=nullptr and position==0) {
        node->next = head;
        head = node;
        return;
    }
    ListNode* current = head;
    ListNode* prev = nullptr;
    while(position--) {
        prev = current;
        current = current->next;
        if(current==nullptr)
            break;
    }
    node->next = current;
    prev->next = node;
}

void delete_node(int position) {
    if(head==nullptr)
        return;
    int p = position;
    position--;
    ListNode* current = head;
    ListNode* prev = nullptr;
    if(head!=nullptr and position==0) {
        head = head->next;
        delete(current);
        return;
    }
    
    while(position--) {
        prev = current;
        current = current->next;
        if(current==nullptr)
            break;
    }
    if(current == nullptr) {
        return;
    }
    prev->next = current->next;
    delete(current);
}


void print_ll() {
    ListNode* temp = head;
    while(temp) {
        cout<<temp->val;
        if(temp->next != nullptr)
            cout<<" ";
        temp = temp->next;
    }
}
