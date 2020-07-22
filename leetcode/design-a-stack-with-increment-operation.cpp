class CustomStack {
public:
    vector<int> arr;
    int maxSize;
    int i = 0;
    vector<int> inc_arr;
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        inc_arr.resize(maxSize+1, 0);
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(i<maxSize) {
            arr[i++] = x;
        }
    }
    
    int pop() {
        if(i>0) {
            inc_arr[i-1] += inc_arr[i];
            int x = arr[i-1];
            x += inc_arr[i];
            inc_arr[i] = 0;
            i--;
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        inc_arr[min(k,i)] += val;
    }
};