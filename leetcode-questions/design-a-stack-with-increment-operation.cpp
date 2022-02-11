class CustomStack {
public:
    int maxSize;
    vector<int> stk;
    vector<int> inc_stk;
    int i=0;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        stk.resize(maxSize);
        inc_stk.resize(maxSize+1, 0);
    }
    
    void push(int x) {
        if(i<maxSize) {
            stk[i++] = x;
        }
    }
    
    int pop() {
        if(i>0) {
            inc_stk[i-1] += inc_stk[i];
            int x = stk[i-1];
            x += inc_stk[i];
            inc_stk[i] = 0;
            i--;
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        inc_stk[min(k,i)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */