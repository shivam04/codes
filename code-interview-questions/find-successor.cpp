using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *getLostMostChild(BinaryTree *node) {
	auto cn = node;
	while(cn->left != nullptr) {
		cn = cn->left;
	}
	return cn;
}

BinaryTree *getRightMostParent(BinaryTree *node) {
	auto cn = node;
	while(cn->parent != nullptr && cn->parent->right==node) {
		cn = cn->parent;
	}
	return cn->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	if(node->right != nullptr) {
		return getLostMostChild(node->right);
	}
  return getRightMostParent(node);
}





using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *getLostMostChild(BinaryTree *node) {
	auto cn = node;
	while(cn->left != nullptr) {
		cn = cn->left;
	}
	return cn;
}

BinaryTree *getRightMostParent(BinaryTree *node) {
	auto cn = node;
	if(cn->parent != nullptr && cn->parent->right==node) {
		cn = cn->parent;
	}
	return cn->parent;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	if(node->right != nullptr) {
		return getLostMostChild(node->right);
	}
  return getRightMostParent(node);
}
