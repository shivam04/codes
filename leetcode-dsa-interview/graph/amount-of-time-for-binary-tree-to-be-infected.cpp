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
    int found = 0;
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> graph;
        convertoToGraph(root, 0, graph);
        queue<int> q;
        q.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int current = q.front();
                q.pop();

                for(int num: graph[current]) {
                    if (visited.find(num) == visited.end()) {
                        q.push(num);
                        visited.insert(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute-1;
    }
    void convertoToGraph(TreeNode* current, int parent, 
            unordered_map<int, unordered_set<int>> &graph) {
        if (current == nullptr) {
            return;
        }

        if (parent != 0) {
            graph[current->val].insert(parent);
        }

        if (current->left != nullptr) {
            graph[current->val].insert(current->left->val);
        }

        if (current->right != nullptr) {
            graph[current->val].insert(current->right->val);
        }
        convertoToGraph(current->left, current->val, graph);
        convertoToGraph(current->right, current->val, graph);
    }
};