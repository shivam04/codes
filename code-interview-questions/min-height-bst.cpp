using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBstUtil(vector<int> array, BST *node, int s, int e) {
  if(e<s)
    return nullptr;
  int mid = (s+e)/2;
  int val = array[mid];
  if(node==nullptr) {
    node = new BST(val);
  } else {
    node->insert(val);
  }
  minHeightBstUtil(array, node, s, mid-1);
  minHeightBstUtil(array, node, mid+1, e);
  return node;
}

BST *minHeightBst(vector<int> array) {
  return minHeightBstUtil(array, nullptr, 0, array.size()-1);
}
