class Solution {
public:
    pair<int,int> getSlope(int x, int y) {
        int p = __gcd(x,y);
        int num = x/p;
        int den = y/p;
        return {num,den};
    }
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<pair<int,int>, int> mp;
        for(vector<int> rectangle: rectangles) {
            pair<int,int> slope = getSlope(rectangle[0], rectangle[1]);
            mp[slope]++;
        }
        long ans = 0;
        for(auto it: mp) {
            long x = (long)it.second;
            ans += (x*(x-1)/2);
        }
        return ans;
    }
};