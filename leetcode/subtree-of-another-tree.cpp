//O(mn)
class Solution {
public:
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)  
            return true;  
        if (root1 == NULL || root2 == NULL)  
            return false; 
        return (root1->val == root2->val &&  
                isIdentical(root1->left, root2->left) &&  
                isIdentical(root1->right, root2->right) );
    }
    bool isSubtree(TreeNode* S, TreeNode* T) {
        if(S == NULL || T == NULL)
            return false;
        if(isIdentical(T,S))
            return true;
        return (S != NULL && (isSubtree(S->left, T) || isSubtree(S->right, T)));
    }
};

//O(n)
#include<bits/stdc++.h>
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
    void  storeInorder(TreeNode* root, string &in) {
        if(root==NULL) {
            in += "$";
            return;
        }
        storeInorder(root->left, in);
        in += to_string(root->val);
        storeInorder(root-> right, in);
    }
    void  storePreorder(TreeNode* root, string &pre) {
        if(root==NULL) {
            pre += "$";
            return;
        }
        pre += to_string(root->val);
        storePreorder(root->left, pre);
        storePreorder(root-> right, pre);
    }
    bool isSubtree(TreeNode* S, TreeNode* T) {
        if(S == NULL || T == NULL)
            return false;
        string inS, inT; 
        storeInorder(S, inS);
        storeInorder(T, inT);
        if(inS.find(inT) == string::npos)
            return false;
        string preS, preT; 
        storePreorder(S, preS);
        storePreorder(T, preT);
        return (preS.find(preT) != string::npos);
    }
};