#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = nullptr);
  void insert(vector<int> values, int i = 0);
};

void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
  BinaryTree* cn = tree;
	BinaryTree* pn = nullptr;
	while(cn != nullptr) {
		BinaryTree* nn;
		if(pn==nullptr || pn == cn->parent) {
			if(cn->left != nullptr) {
				nn = cn->left;
			} else {
				(*callback)(cn);
				nn = cn->right != nullptr ? cn->right : cn->parent;
			}
		} else if(pn == cn->left) {
			(*callback)(cn);
			nn = cn->right != nullptr ? cn->right : cn->parent;
		} else {
			nn = cn->parent;
		}
		pn = cn;
		cn = nn;
	}
}
