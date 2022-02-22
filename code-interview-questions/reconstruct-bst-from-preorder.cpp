using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
BST* reconstructBstUtil(vector<int> pre, int &pI, int key, int mini, 
												int maxi, int size) {
	if(pI>=size)
		return nullptr;
	BST* root = nullptr;
	if(key >= mini and key < maxi) {
		root = new BST(key);
		pI++;
		if(pI < size) {
			root->left = reconstructBstUtil(pre, pI, pre[pI], mini, key, size);
		}
		if(pI < size) {
			root->right = reconstructBstUtil(pre, pI, pre[pI], key, maxi, size);
		}
	}
	return root;
}
BST *reconstructBst(vector<int> preOrderTraversalValues) {
  int pI = 0;
  return reconstructBstUtil(preOrderTraversalValues, pI, preOrderTraversalValues[0],
													 INT_MIN, INT_MAX,preOrderTraversalValues.size());
}
