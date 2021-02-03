class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int len=0;
    list<int> dq;
    MyCircularDeque(int k) {
        len=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        //cout<<len<<" "<<dq.size()<<" insertfront\n";
        if(isFull())
            return false;
        dq.push_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        //cout<<len<<" "<<dq.size()<<" insertlast\n";
        if(isFull())
            return false;
        dq.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty())
            return false;
        dq.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty())
            return false;
        dq.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty())
            return -1;
        return dq.front();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty())
            return -1;
        return dq.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (dq.size()==0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return len==dq.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */