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
    int flag = 0;
    TreeNode* delNodesUtil(TreeNode* root, int delN, vector<TreeNode*> &ans) {
        if(!root)
            return NULL;
        if(root->val == delN) {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            root->left = NULL;
            root->right = NULL;
            root = NULL;
            flag = 1;
            return NULL;
        }
        root->left = delNodesUtil(root->left, delN, ans);
        root->right = delNodesUtil(root->right, delN, ans);
        return root;
    }
    void print(TreeNode* root){
        if(!root)
            return;
        print(root->left);
        cout<<root->val<<", ";
        print(root->right);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        ans.push_back(root);
        vector<TreeNode*> toDel;
        for(int delN : to_delete) {
            flag = 0;
            int i = 0;
            for(TreeNode* node: ans) {
                i+=1;
                TreeNode* p = delNodesUtil(node, delN, ans);
                if(p==NULL)
                    toDel.push_back(node);
                if(flag)
                    break;
            }
        }
        for(TreeNode* node : toDel) {
            int i;
            for(i=0;i<ans.size();i++) {
                if(ans[i] == node) {
                    break;
                }
            }
            if(i<ans.size()) {
                ans.erase (ans.begin()+i);
            }
        }
        return ans;
    }
};


//clean

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
    int flag = 0;
    vector<TreeNode*> ans;
    set<int> s;
    TreeNode* delNodesUtil(TreeNode* root,bool isRoot) {
        if(!root)
            return NULL;
        bool del = (s.find(root->val) != s.end()); 
        if(isRoot and !del)
            ans.push_back(root);
        root->left = delNodesUtil(root->left, del);
        root->right = delNodesUtil(root->right, del);
        return (del ? NULL : root);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int del : to_delete) {
            s.insert(del);
        }
        delNodesUtil(root, true);
        return ans;
    }
};