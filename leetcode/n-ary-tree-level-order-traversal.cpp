class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;  // Create a queue
        q.push(root);
        vector<vector<int>> ans;
        if(!root)
                return ans;
        vector<int> level;
        while (!q.empty()) {
            int n = q.size();
            while (n > 0) {
                Node * p = q.front();
                q.pop();
                level.push_back(p->val);
                for (int i=0; i<p->children.size(); i++)
                    q.push(p->children[i]);
                    n--;
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};