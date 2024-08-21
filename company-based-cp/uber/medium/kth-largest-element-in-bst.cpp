class Solution {
    public:
    Node* kthLargestUtil(Node* root, int k, int &count) {
        if (root == nullptr) {
            return root;
        }
        Node* right = kthLargestUtil(root->right, k, count);
        if (right != nullptr) {
            return right;
        }
        count++;
        if (count == k) {
            return root;
        }
        return kthLargestUtil(root->left, k, count);
    }
    int kthLargest(Node *root, int K) {
        int count = 0;
        Node* node = kthLargestUtil(root, K, count);
        return node->data;
    }
};