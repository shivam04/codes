class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums) {
            mp[n]=1;
        }
        set<int> unq;
        for(auto it: mp) {
            unq.insert(it.first);
        }
        int len = 0;
        for(auto t: unq) {
            if(mp[t-1]==0) {
                int j = 0;
                int cl = 0;
                while(mp[j+t]==1) {
                    j+=1;
                    cl++;
                }
                len = max(len,cl);
            }
        }
        return len;
    }
};