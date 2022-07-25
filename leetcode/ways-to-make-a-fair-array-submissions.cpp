class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int oddSumP = 0, oddSumS = 0;
        int evenSumP = 0, evenSumS = 0;
        int res = 0;
        for(int i=0;i<n;i++) {
            if(i%2==0)
                evenSumS += nums[i];
            else
                oddSumS += nums[i];
        }
        for(int i=0;i<n;i++) {
            int temp = nums[i];
            if(i%2==0)
                evenSumS -= temp;
            else
                oddSumS -= temp;
            if(evenSumP + oddSumS == evenSumS + oddSumP) {
                res++;
            }
            if(i%2==0)
                evenSumP += temp;
            else
                oddSumP += temp;
        }
        return res;
    }
};
