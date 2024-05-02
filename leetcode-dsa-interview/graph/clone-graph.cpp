/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(node->val);
        unordered_map<Node*, vector<Node*>> neighBours;
        queue<Node*> q, newQ;
        unordered_map<Node*, int> visit;
        q.push(node);
        newQ.push(newNode);

        visit[node] = 1;
        unordered_map<Node*, Node*> oldToNewMap;
        oldToNewMap[node] = newNode;
        while(!q.empty()) {
            Node* temp = q.front();
            Node* newTemp = newQ.front();
            q.pop();
            newQ.pop();

            for(Node* nei : temp->neighbors) {
                if (visit[nei] == 0) {
                    q.push(nei);
                    Node* newNei = new Node(nei->val);
                    newQ.push(newNei);
                    neighBours[newTemp].push_back(newNei);
                    visit[nei] = 1;
                    oldToNewMap[nei] = newNei;
                } else {
                    neighBours[newTemp].push_back(oldToNewMap[nei]);
                }
            }
        }

        for(auto it: neighBours) {
            Node* node = it.first;
           node->neighbors = it.second;
        }
        return newNode;
    }
};