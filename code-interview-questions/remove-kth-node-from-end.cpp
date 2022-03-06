#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  int l=0;
	LinkedList* c = head;
	while(c != NULL) {
		c = c->next;
		l++;
	}
	if(k==l) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	k = k%l;
	int p = l-k;
	LinkedList* prev = NULL;
	c = head;
	while(p--) {
		prev = c;
		c = c->next;
	}
	if(c != NULL) {
		prev->next = c->next;
	}
}
