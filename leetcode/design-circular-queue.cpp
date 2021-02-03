class MyCircularQueue {
public:
    int front,rear;
    vector<int> q;
    int size; 
    MyCircularQueue(int k) {
        front = rear = -1; 
        size = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if((front == 0 and rear == size-1) || ((rear+1)%(size) == (front)))
            return false;
        if(front == -1) {
            front = rear = 0;
            q[front] = value;
        } else if(rear == size-1 && front != 0) {
            rear = 0; 
            q[rear] = value; 
        } else {
            q[++rear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front==-1)
            return false;
        int data = q[front];
        q[front] = -1;
        if(front==rear) {
            front = rear = -1;
        } else if(front==size-1) {
            front = 0;
        } else 
            front++;
        return true;
    }
    
    int Front() {
        if(front==-1)
            return -1;
        return q[front];
    }
    
    int Rear() {
        if(rear == -1)
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return (front == -1);
    }
    
    bool isFull() {
        
        return ((front == 0 and rear == size-1) || ((rear+1)%(size) == (front)));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */