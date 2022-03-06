#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

int getDepth(AncestralTree *topAncestor, AncestralTree *descendant) {
	int d = 0;
	while(descendant != topAncestor) {
		d++;
		descendant = descendant->ancestor;
	}
	return d;
}

AncestralTree *getYoungestCommonAncestorUtil(AncestralTree *lowerDescendant,
                                         AncestralTree *higherDescendant, int diff) {
	while(diff>0) {
		lowerDescendant = lowerDescendant->ancestor;
		diff--;
	}
	while(lowerDescendant!=higherDescendant) {
		lowerDescendant = lowerDescendant->ancestor;
		higherDescendant = higherDescendant->ancestor;
	}
	return higherDescendant;
}

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
	int h1 = getDepth(topAncestor, descendantOne);
	int h2 = getDepth(topAncestor, descendantTwo);
	if(h1 > h2) {
		return getYoungestCommonAncestorUtil(descendantOne, descendantTwo, h1-h2);
	} 
  return getYoungestCommonAncestorUtil(descendantTwo, descendantOne, h2-h1);
}
