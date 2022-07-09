stack<int> s;
int mini = INT_MAX;
MinStack::MinStack() {
    while(!s.empty())
    s.pop();
}

void MinStack::push(int x) {
    if(s.empty()) {
        mini = x;
        s.push(x);
    } else if(x<mini) {
        s.push(2*x - mini);
        mini = x;

    } else {
        s.push(x);
    }
}

void MinStack::pop() {
    if(s.empty())
        return;
    int t = s.top();
    if(t < mini) {
        mini = 2*mini - t;
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty())
        return -1;
    int t = s.top();
    return (t<mini) ? mini : t;
}

int MinStack::getMin() {
    if(s.empty())
        return -1;
    return mini;
}