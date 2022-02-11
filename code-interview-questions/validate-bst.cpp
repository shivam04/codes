class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBstHelper(BST *tree, int minVal,int maxVal) {
	if(tree->value < minVal || tree->value>=maxVal) {
		return false;
	}
	if(tree->left != nullptr && !validateBstHelper(tree->left, minVal, tree->value)) {
		return false;
	}
	if(tree->right != nullptr && !validateBstHelper(tree->right, tree->value, maxVal)) {
		return false;
	}
	return true;
}

bool validateBst(BST *tree) {
	return validateBstHelper(tree, INT_MIN, INT_MAX);
}

