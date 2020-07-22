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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        //cout<<len<<"\n";
        if(len==0) {
            return NULL;
        }
        int max = *max_element(nums.begin(), nums.end());
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode* node = new TreeNode(max);
        vector<int> vb(maxi);
        vector<int> ve(len-maxi-1);
        copy(nums.begin(), nums.begin()+maxi,vb.begin());
        copy(nums.begin() + maxi + 1, nums.end(),ve.begin());
        //cout<<vb.size()<<" "<<ve.size()<<"\n";
        int k = len-maxi;
        node->left = constructMaximumBinaryTree(vb);
        node->right = constructMaximumBinaryTree(ve);
        return node;
    }
};