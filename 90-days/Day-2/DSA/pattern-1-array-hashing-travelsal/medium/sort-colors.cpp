class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(int color:nums) {
            r+=(color==0);
            w+=(color==1);
            b+=(color==2);
        }
        w+=r;
        b+=w;
        for(int i=0;i<b;i++) {
            if(i<r) {
                nums[i]=0;
            }else if(i<w) {
                nums[i]=1;
            } else {
                nums[i]=2;
            }
        }
    }
};