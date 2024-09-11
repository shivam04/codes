// O(NlogN) O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        for (int i=1;i<nums.size();i++) {
            if (nums[i] != nums[i-1]) {
                v.push_back(nums[i]);
            }
        }
        int cnt = 0;
        int maxCnt = 0;
        for (int i=0;i<v.size();i++) {
            if (i > 0 and v[i] == v[i-1] + 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};



// O(N) O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxCnt = 0;
        unordered_set<int> s;
        for (auto num: nums) {
            s.insert(num);
        }

        for (int i=0;i<nums.size();i++) {
            if (s.find(nums[i] - 1) == s.end()) {
                int j = nums[i];
                while (s.find(j) != s.end())
                    j++;
                maxCnt = max(maxCnt, j-nums[i]);
            }
        }

        return maxCnt;
    }
};