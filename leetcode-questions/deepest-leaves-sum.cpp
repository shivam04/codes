/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int total = 0;
            for(int i=0;i<n;i++) {
                TreeNode* head = q.front();
                q.pop();
                total += head->val;
                    if(head->left != NULL)
                        q.push(head->left);
                    if(head->right != NULL)
                        q.push(head->right);
            }
            sum = total;
        }
        return sum;
    }
    
};