#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    public:
        int val;
        string color;
        TreeNode *left, *right, *parent;
        TreeNode(int val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }
};

class RedBlackTree {
    private:
        TreeNode* root;
        TreeNode* NIL;
        void leftRotate(TreeNode* x) {
            TreeNode* y = x->right;
            x->right = y->left;
            if (y->left != NIL) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        // Utility function to perform right rotation
        void rightRotate(TreeNode* x) {
            TreeNode* y = x->left;
            x->left = y->right;
            if (y->right != NIL) {
                y->right->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->right) {
                x->parent->right = y;
            }
            else {
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }
        void fixInsert(TreeNode* k) {
            while(k != root and k->parent->color == "RED") {
                if (k->parent == k->parent->parent->left) {
                    TreeNode* u = k->parent->parent->right;
                    if (u->color == "RED") {
                        k->parent->color = "BLACK";
                        u->color = "BLACK";
                        k->parent->parent->color = "RED";
                        k = k->parent->parent;
                    } else {
                        if (k == k->parent->right) {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = "BLACK";
                        k->parent->parent->color = "RED";
                        rightRotate(k->parent->parent);
                    }
                } else {
                    TreeNode* u = k->parent->parent->left; // uncle
                    if (u->color == "RED") {
                        k->parent->color = "BLACK";
                        u->color = "BLACK";
                        k->parent->parent->color = "RED";
                        k = k->parent->parent;
                    }
                    else {
                        if (k == k->parent->left) {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = "BLACK";
                        k->parent->parent->color = "RED";
                        leftRotate(k->parent->parent);
                    }
                }
            }
        }
        void inorderHelper(TreeNode* node) {
            if (node != NIL) {
                inorderHelper(node->left);
                cout << node->val << " ";
                inorderHelper(node->right);
            }
        }

        // Search helper function
        TreeNode* searchHelper(TreeNode* node, int data) {
            if (node == NIL || data == node->val) {
                return node;
            }
            if (data < node->val) {
                return searchHelper(node->left, data);
            }
            return searchHelper(node->right, data);
        }
    public:
        RedBlackTree() {
            NIL = new TreeNode(0);
            NIL->color = "BLACK";
            root = NIL;
        }

        void insert(int val) {
            TreeNode* newNode = new TreeNode(val);
            TreeNode* parent = nullptr;
            TreeNode* current = root;

            while (current != nullptr) {
                parent = current;
                if (newNode->val < current->val) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            newNode->parent = parent;

            if (parent == nullptr) {
                root = newNode;
            } else if (parent->val > newNode->val) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }

            if (newNode->parent == nullptr) {
                newNode->color = "BLACK";
                return;
            }

            if (newNode->parent->parent == nullptr) {
                return;
            }
            fixInsert(newNode);
        }
        void inorder() { 
            inorderHelper(root); 
        }

        // Search function
        TreeNode* search(int data) {
            return searchHelper(root, data);
        }
};

int main() {
    RedBlackTree rbt;

    // Inserting elements
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);

    // Inorder traversal
    cout << "Inorder traversal:" << endl;
    rbt.inorder(); // Output: 10 15 20 30

    // Search for a node
    cout << "\nSearch for 15: "
        << (rbt.search(15) != rbt.search(0))
        << endl; // Output: 1 (true)
    cout << "Search for 25: "
        << (rbt.search(25) != rbt.search(0))
        << endl; // Output: 0 (false)

    return 0;
}