using namespace std;

// This is an input class. Do not edit. O(N)
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool isAncestor(BST *nodeOne, BST *nodeTwo) {
	if(!nodeTwo)
		return false;
	if(nodeTwo == nodeOne)
		return true;
	return isAncestor(nodeOne, nodeTwo->left) or isAncestor(nodeOne, nodeTwo->right);
}

bool isDecendent(BST *nodeOne, BST *nodeTwo) {
	if(!nodeOne)
		return false;
	if(nodeTwo == nodeOne)
		return true;
	return isDecendent(nodeOne->left, nodeTwo) or isDecendent(nodeOne->right, nodeTwo);
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
	return ((isAncestor(nodeTwo, nodeOne) and isDecendent(nodeTwo, nodeThree)) or (isAncestor(nodeTwo, nodeThree) and isDecendent(nodeTwo, nodeOne)));
}



using namespace std;

// This is an input class. Do not edit. O(h)
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

bool isDecendent(BST *nodeOne, BST *nodeTwo) {
	if(!nodeOne)
		return false;
	if(nodeTwo == nodeOne)
		return true;
	return nodeTwo->value < nodeOne->value ? 
		isDecendent(nodeOne->left, nodeTwo) 
		: isDecendent(nodeOne->right, nodeTwo);
}

bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
	return ((isDecendent(nodeOne, nodeTwo) and isDecendent(nodeTwo, nodeThree)) or (isDecendent(nodeThree, nodeTwo) and isDecendent(nodeTwo, nodeOne)));
}
