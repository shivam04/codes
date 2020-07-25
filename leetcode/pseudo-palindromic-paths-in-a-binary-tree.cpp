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
    int checkPalindrome(string s) {
        map<int, int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        int no = 0;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            if(it->second % 2) {
                no++;
            }
        }
        return (no <= 1);
    }
    int pseudoPalindromicPathsUtil(TreeNode* root, string s) {
        if(!root) {
            return 0;
        }
        if(root and !root->left and !root->right) {
            return checkPalindrome(s + to_string(root->val));
        }
        int a = pseudoPalindromicPathsUtil(root->left, s + to_string(root->val));
        int b = pseudoPalindromicPathsUtil(root->right, s + to_string(root->val));
        return a+b;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        return pseudoPalindromicPathsUtil(root, "");
    }
};