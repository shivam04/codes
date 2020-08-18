class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int lis[n];
        lis[0] = 1;
        for(int i=1;i<n;i++) {
            lis[i] = 1;
            for(int j=0;j<i;j++) {
                if ( nums[i] > nums[j] && lis[i] < lis[j] + 1)  {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        return *max_element(lis, lis+n); 
    }
};

//optimize O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++) {
            auto it = lower_bound(temp.begin(),temp.begin()+len, nums[i]);
            if(it == temp.begin() + len){
                temp.push_back(nums[i]);
                len++;
            }else{
                *it = nums[i];
            }
                
        }
        return len; 
    }
};