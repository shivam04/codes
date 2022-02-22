using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
void findKthLargestValueInBstUtil(BST *tree, int k, int &c, int &ans) {
	if (tree == NULL || c >= k)
		return;
	findKthLargestValueInBstUtil(tree->right, k, c, ans);
	c++;
	if(c==k){
		ans = tree->value;
		return;
	}
	findKthLargestValueInBstUtil(tree->left, k, c, ans);
}
int findKthLargestValueInBst(BST *tree, int k) {
  int c = 0;
	int ans = -1;
	findKthLargestValueInBstUtil(tree, k, c, ans);
  return ans;
}
