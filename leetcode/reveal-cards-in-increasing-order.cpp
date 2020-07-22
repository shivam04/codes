class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        int p = n/2;
        if(n%2)
            p++;
        deque<int> d;      
        for(int i=0;i<n;i++) {
            d.push_back(i);
        }
        vector<int> ans(n);
        for(int card: deck) {
            ans[d.front()] = card;
            d.pop_front();
            if(!d.empty()) {
                d.push_back(d.front());
                d.pop_front();
            }
        }
        return ans;
    }
};