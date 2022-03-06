#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    for(int i=0;i<str.length();i++) {
			this->insertInfoSuffixTree(i, str);
		}
  }
	
	void insertInfoSuffixTree(int i, string str) {
		TrieNode *node = this->root;
		for(int j=i;j<str.length();j++) {
			char l = str[j];
			if(node->children.find(l) == node->children.end()) {
				TrieNode *newNode = new TrieNode();
				node->children.insert({l, newNode});
			}
			node = node->children[l];
		}
		node->children.insert({this->endSymbol, nullptr});
	}

  bool contains(string str) {
    TrieNode *node = this->root;
		for(auto l: str) {
			if(node->children.find(l) == node->children.end()) {
				return false;
			}
			node = node->children[l];
		}
    return node->children.find(this->endSymbol) != node->children.end();
  }
};
