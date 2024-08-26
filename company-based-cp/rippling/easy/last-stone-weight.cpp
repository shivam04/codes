class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for (int stone: stones) {
            maxH.push(stone);
        }
        
        while(maxH.size() > 1) {
            int a = maxH.top();
            maxH.pop();
            int b = maxH.top();
            maxH.pop();
            if (a == b) {
                continue;
            } else {
                int c = a - b;
                maxH.push(c);
            }
        }
        if (maxH.size() == 1) {
            return maxH.top();
        }
        return 0;
    }
};