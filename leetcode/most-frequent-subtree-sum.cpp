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
    int findFrequentTreeSum(TreeNode* root,unordered_map<int, int> &s, int &maxi) {
        if(!root)
            return 0;
        if (root->left == NULL && root->right == NULL) {
            s[root->val]++;
            maxi = max(maxi, s[root->val]);
            return root->val; 
        }
        int ls = findFrequentTreeSum(root->left, s, maxi);
        int rs = findFrequentTreeSum(root->right, s, maxi);
        root->val += (ls+rs);
        s[root->val]++;
        maxi = max(maxi, s[root->val]);
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> s;
        int maxi = 0;
        findFrequentTreeSum(root, s, maxi);
        vector<int> ans;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(it->second == maxi) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};