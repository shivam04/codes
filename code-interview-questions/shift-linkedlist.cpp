using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
	int n = 1;
	LinkedList* c = head;
	while(c->next != nullptr) {
		c = c->next;
		n++;
	}
	int pos = abs(k)%n;
	if(pos==0)
		return head;
	int np = k>0 ? n-pos : pos;
	LinkedList* nt = head;
	for(int i=1;i<np;i++) {
		nt = nt->next;
	}
	LinkedList* ans = nt->next;
	nt->next = nullptr;
	c->next = head;
	return ans;
}
