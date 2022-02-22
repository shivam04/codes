using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

struct TreeInfo {
	bool isBalanace;
	int height;
};

TreeInfo getTreeInfo(BinaryTree *node) {
	if(node==nullptr)
		return TreeInfo{true, -1};
	auto leftTreeInfo = getTreeInfo(node->left);
	auto rightTreeInfo = getTreeInfo(node->right);
	bool isBalanced = (leftTreeInfo.isBalanace && rightTreeInfo.isBalanace && 
		abs(leftTreeInfo.height-rightTreeInfo.height)<=1);
	int height = max(leftTreeInfo.height, rightTreeInfo.height) + 1;
	return TreeInfo{isBalanced, height};
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
	auto treeInfo = getTreeInfo(tree);
  return treeInfo.isBalanace;
}
