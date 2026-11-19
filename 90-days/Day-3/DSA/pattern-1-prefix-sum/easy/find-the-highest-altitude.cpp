class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int largestAltitudRes = 0;
        int start = 0;
        for (int g: gain) {
            start+=g;
            largestAltitudRes = max(largestAltitudRes, start);
        }
        return largestAltitudRes;
    }
};