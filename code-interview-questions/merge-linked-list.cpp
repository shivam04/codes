#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
	LinkedList* cOne = headOne;
	LinkedList* cTwo = headTwo;
	LinkedList* cOnePrev = nullptr;
  while(cOne != nullptr and cTwo != nullptr) {
		if(cOne->value < cTwo->value) {
			cOnePrev = cOne;
			cOne = cOne->next;
		} else {
			if(cOnePrev != nullptr)
				cOnePrev->next = cTwo;
			cOnePrev = cTwo;
			cTwo = cTwo->next;
			cOnePrev->next = cOne;
		}
	}
	if(cOne == nullptr) {
		cOnePrev->next = cTwo;
	}
	
  return headOne->value < headTwo->value ? headOne : headTwo;
}
