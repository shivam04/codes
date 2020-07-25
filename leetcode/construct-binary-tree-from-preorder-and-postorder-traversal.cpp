/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    void printInorder (TreeNode* node) { 
        if (node == NULL) 
            return; 
        printInorder(node->left); 
        cout<<node->val<<" "; 
        printInorder(node->right); 
    } 
    TreeNode* constructFromPrePostUtil(vector<int> pre, vector<int> post, int prel, int preh, int postl, int posth) {
        if (prel >= preh)  
            return NULL;  
        TreeNode* root = new TreeNode(pre[prel]);
        if(prel + 1 < preh) {
            int i = mp[pre[prel+1]] - postl + 1;
            root->left = constructFromPrePostUtil(pre, post, prel+1, prel+1+i, postl, postl+i);
            root->right = constructFromPrePostUtil(pre, post, prel+1+i, preh, postl+i, posth-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int size = pre.size();
        mp.clear();
        int preIndex = 0;
        for(int i = 0; i < size; i++) {
            mp[post[i]] = i;
        }
        TreeNode* node = constructFromPrePostUtil(pre, post, 0, size, 0, size);
        //printInorder(node);
        return node;
    }
};