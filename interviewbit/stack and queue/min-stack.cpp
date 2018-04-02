stack<int> s;
stack<int> minSt;
MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }
    while(!minSt.empty()){
        minSt.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if(minSt.size() == 0){
        minSt.push(x);
    }
    else{
        if(x <= minSt.top()){
            minSt.push(x);
        }
        else{
            minSt.push(minSt.top());
        }
    }
}

void MinStack::pop() {
    if(!s.empty()){
        s.pop();
        minSt.pop();
    }
}

int MinStack::top() {
    if(!s.empty())
        return s.top();
    return -1;
}

int MinStack::getMin() {
    if(!s.empty())
        return minSt.top();
    return -1;
}

