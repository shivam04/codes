class StockSpanner {
public:
    stack<int> s,w;
    StockSpanner() {
        while(!s.empty()) {
            s.pop();
        }
        while(!w.empty()) {
            w.pop();
        }
    }
    
    int next(int price) {
        int ans = 1;
        while(!s.empty() and (s.top() <= price)) {
            s.pop();
            ans+=w.top();
            w.pop();
        }
        s.push(price);
        w.push(ans);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */