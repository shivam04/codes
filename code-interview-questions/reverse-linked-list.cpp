using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList* current = head;
	LinkedList *next = nullptr, *prev = nullptr;
	while(current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current= next;
	}
	head = prev;
  return head;
}
