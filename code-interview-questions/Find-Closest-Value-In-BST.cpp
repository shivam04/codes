class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
void findClosestValueInBstUtil(BST *tree, int target, int &ans, int &minD) {
	if(!tree)
		return;
	if(abs(tree->value - target) < minD) {
		minD = abs(tree->value - target);
		ans = tree->value;
	}
	if(target > tree->value)
		findClosestValueInBstUtil(tree->right, target, ans, minD);
	findClosestValueInBstUtil(tree->left, target, ans, minD);
}
int findClosestValueInBst(BST *tree, int target) {
  int ans = -1;
	int minD = 1000000000;
	findClosestValueInBstUtil(tree, target, ans, minD);
  return ans;
}
