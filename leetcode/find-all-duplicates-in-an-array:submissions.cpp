class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int p = abs(a[i])-1;
            if(a[p]>=0) {
                a[p] = -a[p];
            } else {
                ans.push_back(abs(a[i]));
            }
        }
        return ans;
    }
};