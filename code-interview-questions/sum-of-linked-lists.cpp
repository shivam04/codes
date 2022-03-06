using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  LinkedList* c1 = linkedListOne;
	LinkedList* c2 = linkedListTwo;
	LinkedList* p = new LinkedList(-100000);
	LinkedList* cp = p;
	int c = 0;
	while(c1!=nullptr and c2!=nullptr) {
		int s = c1->value + c2->value + c;
		c = s/10;
		int num = s%10;
		LinkedList* temp = new LinkedList(num);
		c1 = c1->next;
		c2 = c2->next;
		cp->next = temp;
		cp = cp->next;
	}
	while(c1!=nullptr) {
		int s = c1->value + c;
		c = s/10;
		int num = s%10;
		LinkedList* temp = new LinkedList(num);
		c1 = c1->next;
		cp->next = temp;
		cp = cp->next;
	}
	while(c2!=nullptr) {
		int s = c2->value + c;
		c = s/10;
		int num = s%10;
		LinkedList* temp = new LinkedList(num);
		c2 = c2->next;
		cp->next = temp;
		cp = cp->next;
	}
	if(c>0) {
		LinkedList* temp = new LinkedList(c);
		cp->next = temp;
		cp = cp->next;
	}
	p = p->next;
  return p;
}