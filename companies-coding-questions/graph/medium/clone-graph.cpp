/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==nullptr) {
        return nullptr;
    }
    queue<UndirectedGraphNode*> q,nq;
    vector<UndirectedGraphNode*> nei;
    q.push(node);
    UndirectedGraphNode* nnode = new UndirectedGraphNode(node->label);
    nq.push(nnode);
    unordered_map<UndirectedGraphNode*, int> visit;
    unordered_map<int, UndirectedGraphNode*> pNode;
    pNode[node->label] = nnode;
    visit[node] = 1;
    while(!q.empty()) {
        UndirectedGraphNode* u = q.front();
        UndirectedGraphNode* nu = nq.front();
        q.pop();
        nq.pop();
        for(int i=0; i<u->neighbors.size();i++) {
            UndirectedGraphNode* v =  u->neighbors[i];
            if(visit[v]==0) {
                UndirectedGraphNode* nv = new UndirectedGraphNode(v->label);
                nei.push_back(nv);
                q.push(v);
                nq.push(nv);
                visit[v]=1;
                pNode[v->label] = nv;
            } else {
                UndirectedGraphNode* nv = pNode[u->neighbors[i]->label];
                nei.push_back(nv);
            }
        }
        nu->neighbors = nei;
        nei.clear();
    }
    return nnode;
}
