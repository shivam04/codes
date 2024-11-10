// O(n^2)
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ans;
        vector<vector<int>> yToXs(101);
        for (vector<int>& r : rectangles) {
            yToXs[r[1]].push_back(r[0]);
        }

        for (auto &xs: yToXs) {
            sort(xs.begin(), xs.end());
        }
        
        for (vector<int>& p : points) {
            int count = 0;
            for (int y s= p[1]; y < 101; ++y) {
                vector<int>& xs = yToXs[y];
                count += xs.end() - lower_bound(xs.begin(), xs.end(), p[0]);
            }
            ans.push_back(count);
        }

        return ans;
    }
};



// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n==0)
            return 0;
        vector<int> lis;
        lis.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > lis.back()) {
                lis.push_back(nums[i]);
            } else {
                int low = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[low] = nums[i];
            }
        }
        return lis.size();
        
    }
};