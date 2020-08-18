/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* nextRight(Node* curr) {
        Node *p = curr->next;
        while(p) {
            if(p->left)
                return p->left;
            if(p->right)
                return p->right;
            p = p->next;
        }
        return NULL;
    }
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node* curr = root;
        curr->next = NULL;
        while(curr) {
            Node* node = curr;
            while(node) {
                if(node->left) {
                     if(node->right)
                         node->left->next = node->right;
                    else
                        node->left->next = nextRight(node);
                } if(curr->right) {
                    node->right->next = nextRight(node);
                }
                node = node->next;
            }
            if(curr->left)
                curr = curr->left;
            else if(curr->right)
                curr = curr->right;
            else
                curr = nextRight(curr);
        }
        return root;
    }
};