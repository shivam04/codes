class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        k = n-k;
        int m = k/2;
        for(int i=0;i<m;i++) {
            swap(nums[i], nums[k-i-1]);
        }

        vector<int> rest(nums.begin() + k, nums.end());
        n = rest.size();
        m = n/2;
        for (int i=0;i<m;i++) {
            swap(rest[i], rest[n-i-1]);
        }

        n = nums.size();
        int j = 0;
        for (int i=k;i<n;i++) {
            nums[i] = rest[j++];
        }

        m = n/2;

        for(int i=0;i<m;i++) {
            swap(nums[i], nums[n-i-1]);
        }

    }
};