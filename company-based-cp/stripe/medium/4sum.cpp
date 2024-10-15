// TLE
class Solution {
public:
    bool allDifferent(int a, int b, int c, int d) {
        return !(a==b || a==c || a==d || b==c || b==d || c==d);
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> sumNums;
        int n = nums.size();
        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                mp[nums[i] + nums[j]].push_back({i,j});
                sumNums.push_back({nums[i] + nums[j], {i,j}});
            }
        }
        map<int,map<int,int>> visited;
        set<vector<int>> tempAns;
        for (int i=0;i<sumNums.size();i++) {
            int remainingTarget = target - sumNums[i].first;
            if (mp.find(remainingTarget) != mp.end()) {
                for (auto comb: mp[remainingTarget]) {
                    int a = sumNums[i].second.first;
                    int b = sumNums[i].second.second;
                    int c = comb.first;
                    int d = comb.second;
                    visited[c][d] = 1;
                    visited[a][b] = 1;
                    if (allDifferent(a, b, c, d)) {
                        vector<int> arr = {nums[a], nums[b], nums[c], nums[d]};
                        sort(arr.begin(), arr.end());
                        tempAns.insert(arr);
                    }
                }
            }
        }

        vector<vector<int>> ans(tempAns.begin(), tempAns.end());
        return ans;
    }
};


// O(N^3) pass solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); //size of the array
        set<vector<int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                set<long long> hashset;
                for (int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};