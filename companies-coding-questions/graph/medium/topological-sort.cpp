class Node {
    public:
        int val;
        vector<Node *> deps;
        int numOfPreqs;
        Node(int val);
};

Node::Node(int v) {
    val = v;
    numOfPreqs = 0;
}

class Graph {
    public:
        vector<Node *> nodes;
		unordered_map<int, Node*> graph;
		Graph(int numNodes);
		void addDep(int val, int dep);
		void addNode(int val);
		Node *getNode(int val);
};

Graph::Graph(int numNodes) {
    nodes = {};
    for(int i=1;i<=numNodes; i++) {
        addNode(i);
    }
}

void Graph::addNode(int node) {
    graph[node] = new Node(node);
    nodes.push_back(graph[node]);
}

Node* Graph::getNode(int v) {
    if(graph.find(v) == graph.end())
		addNode(v);
    return graph[v];
}

void Graph::addDep(int v, int dep) {
    Node* parent = getNode(v);
    Node* child = getNode(dep);
    parent->deps.push_back(child);
    child->numOfPreqs++;
}

Graph* createGraph(int A, vector<vector<int> > &B) {
    Graph *graph = new Graph(A);
    for(vector<int> edge: B) {
        graph->addDep(edge[0], edge[1]);
    }
    return graph;
}

void removeDeps(Node *node, vector<Node *> &nodesWithNoPrereqs) {
    while(!node->deps.empty()) {
        Node* dep = node->deps.back();
        node->deps.pop_back();
        dep->numOfPreqs--;
        if(!dep->numOfPreqs)
            nodesWithNoPrereqs.push_back(dep);
    }
    sort(nodesWithNoPrereqs.begin(), nodesWithNoPrereqs.end(), [](Node* a, Node* b) {
        return a->val < b->val;
    });
    reverse(nodesWithNoPrereqs.begin(), nodesWithNoPrereqs.end());
}

vector<int> getOrderedNode(Graph* graph) {
    for(Node* node: graph->nodes) {
        sort(node->deps.begin(), node->deps.end(), [](Node* a, Node* b) {
            return a->val < b->val;
        });
        reverse(node->deps.begin(), node->deps.end());
    }
    vector<int> orderedJobs = {};
    vector<Node*> nodesWithNoPrereqs(graph->nodes.size());
    auto it = copy_if(graph->nodes.begin(), graph->nodes.end(), 
        nodesWithNoPrereqs.begin(), [](Node* node) {
            return node->numOfPreqs==0;
        });
    nodesWithNoPrereqs.resize(distance(nodesWithNoPrereqs.begin(), it));
    sort(nodesWithNoPrereqs.begin(), nodesWithNoPrereqs.end(), [](Node* a, Node* b) {
        return a->val < b->val;
    });
    reverse(nodesWithNoPrereqs.begin(), nodesWithNoPrereqs.end());
    while(nodesWithNoPrereqs.size()) {
        Node* node = nodesWithNoPrereqs.back();
        nodesWithNoPrereqs.pop_back();
        orderedJobs.push_back(node->val);
        removeDeps(node, nodesWithNoPrereqs);
    }
    bool isOrdered = true;
    for(Node *node: graph->nodes) {
        if(node->numOfPreqs){
            isOrdered = false;
        }
    }
    return isOrdered ? orderedJobs : vector<int>{};
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    Graph *graph = createGraph(A, B);
    return getOrderedNode(graph);
}
