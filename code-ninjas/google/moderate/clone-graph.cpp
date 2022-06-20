/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node) {
    if(node==nullptr) {
        return nullptr;
    }
    queue<graphNode*> q,nq;
    vector<graphNode*> nei;
    q.push(node);
    graphNode* nnode = new graphNode(node->data);
    nq.push(nnode);
    unordered_map<graphNode*, int> visit;
    unordered_map<int, graphNode*> pNode;
    pNode[node->data] = nnode;
    visit[node] = 1;
    while(!q.empty()) {
        graphNode* u = q.front();
        graphNode* nu = nq.front();
        q.pop();
        nq.pop();
        for(int i=0; i<u->neighbours.size();i++) {
            graphNode* v =  u->neighbours[i];
            if(visit[v]==0) {
                graphNode* nv = new graphNode(v->data);
                nei.push_back(nv);
                q.push(v);
                nq.push(nv);
                visit[v]=1;
                pNode[v->data] = nv;
            } else {
                graphNode* nv = pNode[u->neighbours[i]->data];
                nei.push_back(nv);
            }
        }
        nu->neighbours = nei;
        nei.clear();
    }
    return nnode;
}