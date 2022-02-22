#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  LinkedList* slow = head->next;
	LinkedList* fast = head->next->next;
	while(slow!=fast) {
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	while(slow!=fast) {
		slow = slow->next;
		fast = fast->next;
	}
  return slow;
}
