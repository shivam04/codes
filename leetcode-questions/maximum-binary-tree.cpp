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
        if(len==0) {
            return NULL;
        }
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();
        TreeNode* n = new TreeNode(nums[maxi]);
        vector<int> vectl(maxi);
        vector<int> vectr(len - maxi-1);
        copy(nums.begin(), nums.begin()+maxi,vectl.begin());
        copy(nums.begin() + maxi + 1, nums.end(),vectr.begin());
        n->left = constructMaximumBinaryTree(vectl);
        n->right = constructMaximumBinaryTree(vectr);
        return n;
    }
};