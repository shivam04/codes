using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};
int nodeDepths(BinaryTree *root) {
	queue<BinaryTree*> q;
	q.push(root);
	int lvl = 0;
	int ans = 0;
	while(!q.empty()) {
		int s = q.size();
		ans += s*lvl;
		while(s--) {
			BinaryTree* r = q.front();
			q.pop();
			if(r->left) {
				q.push(r->left);
			}
			if(r->right) {
				q.push(r->right);
			}
		}
		lvl++;
	}
	return ans;
}
