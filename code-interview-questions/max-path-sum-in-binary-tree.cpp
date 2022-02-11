#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

int maxPathSumUtil(BinaryTree *tree, int &ans) {
	if(tree == NULL)
		return 0;
	if(tree->left == NULL and tree->right == NULL) {
		ans = max(ans, tree->value);
		return tree->value;
	}
	int ls = maxPathSumUtil(tree->left, ans);
	int rs = maxPathSumUtil(tree->right, ans);
	if(tree->left and tree->right) {
		ans = max(ans, max(tree->value, ls+rs+tree->value));
		ans = max(ans, max(ls+tree->value, rs+tree->value));
		return max(ls, rs) + tree->value;
	} else if(tree->left) {
		ans = max(ans, max(tree->value, ls+tree->value));
		return ls + tree->value;
	} else if(tree->right) {
		ans = max(ans, max(tree->value, rs+tree->value));
		return rs + tree->value;
	}
	return 0;
}

int maxPathSum(BinaryTree tree) {
	int ans = INT_MIN;
  maxPathSumUtil(&tree,ans);
  return ans;
}
