class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        //cout<<n<<"\n";
        for (int num:  nums) {
            mp[num] += 1;
        }
        for(auto it: mp) {
           // cout<<it.first<<" "<<it.second<<"\n";
            if (it.second > n/2) {
                return it.first;
            }
        }
        return -1;
    }
};