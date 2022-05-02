class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[nums[i] & nums[j]]++;
            }
        }
        for(auto it: mp) {
            int k = it.first;
            int cnt = it.second;
            for (int i = 0; i < n; ++i) {
                int num = nums[i];
                if((k&num)==0) {
                    res += (cnt);
                }
            }
        }
        return res;
    }
};