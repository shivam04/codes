class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(); 
        vector<pair<int, int>> aug; 
        for (int i = 0; i < n; ++i) aug.push_back({capital[i], profits[i]}); 
        
        sort(aug.begin(), aug.end()); 
        
        priority_queue<int> pq; 
        for (int i = 0; k; --k) {
            for (; i < n && aug[i].first <= w; ++i) pq.push(aug[i].second); 
            if (pq.size()) { w += pq.top(); pq.pop(); }
        }
        return w; 
    }
};