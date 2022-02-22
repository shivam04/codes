using namespace std;

// This is an input class. Do not edit.
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
int height(BinaryTree *tree, int &ans) {
	if(tree==nullptr)
		return 0;
	int lh = height(tree->left, ans);
	int rh = height(tree->right, ans);
	ans = max(ans, 1+lh+rh);
	return 1 + max(lh, rh);
}
int binaryTreeDiameter(BinaryTree *tree) {
  int ans = -1;
	height(tree, ans);
  return ans-1;
}
