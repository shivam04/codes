/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode* nextRight(TreeLinkNode* curr) {
    TreeLinkNode *p = curr->next;
    while(p) {
        if(p->left)
            return p->left;
        if(p->right)
            return p->right;
        p = p->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* current = A;
    while(current) {
        TreeLinkNode* node = current;
        while(node) {
            if(node->left) {
                if(node->right)
                    node->left->next = node->right;
                else
                    node->left->next = nextRight(node);
            }
            if(node->right) {
                node->right->next = nextRight(node);
            }
            node = node->next;
        }
        if(current->left)
            current = current->left;
        else if(current->right)
            current = current->right;
        else 
            current = nextRight(current);
    }
}
