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
    map < int, vector <TreeNode*> > m;
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N==1) {
            TreeNode* node = new TreeNode();
            vector<TreeNode*> ans;
            ans.push_back(node);
            return ans;
        }
        if(m.count(N)) return m[N];
        vector <TreeNode*> ans;
        int req = N-1;
        for(int l=1;l<req;l++) {
            int r = req - l;
            if(l==2 and r==2) continue;
            vector <TreeNode*> leftPart = allPossibleFBT(l);
            vector <TreeNode*> rightPart = allPossibleFBT(r);
            for(int j = 0; j < leftPart.size(); j++) {
                for(int k = 0; k < rightPart.size(); k++) {
                    TreeNode* root = new TreeNode();
                    root->left = leftPart[j];
                    root->right = rightPart[k];
                    ans.push_back(root);
                }
            }
        }
        return m[N] = ans;
    }
};