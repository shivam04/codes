using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

map<int, vector<int>> graph;
void dfs1(BinaryTree *tree, BinaryTree *parent) {
	if(!tree)
		return;
	if(parent!=NULL) {
		graph[parent->value].push_back(tree->value);
		graph[tree->value].push_back(parent->value);
	}
	dfs1(tree->left, tree);
	dfs1(tree->right, tree);
}
void dfs2(int source, vector<int> &ans, int k) {
	queue<int> q;
	q.push(source);
	int lvl = 0;
	vector<bool> visit(graph.size()+10, false);
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			int s = q.front();
			visit[s] = true;
			if(lvl == k) {
				ans.push_back(s);
			}
			q.pop();
			for(int x : graph[s]) {
				if(!visit[x])
					q.push(x);
			}
		}
		lvl++;
	}
}

vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
	graph.clear();
	vector<int> ans;
  dfs1(tree, NULL);
	dfs2(target, ans, k);
  return ans;
}
