class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if(n==0) {
            int mid = m/2;
            if(m%2==0) {
                return (nums2[mid-1]+nums2[mid])/2.0;
            }
            return (double)nums2[mid];
        }
        int midOfTwo = (n+m+1)/2;
        int l = 0;
        int h = n;
        while(l<=h) {
            int mid = (l+h)/2;
            int ls1 = mid;
            int ls2 = midOfTwo - mid;
            double le1 = ls1>0 ? nums1[ls1-1]:-1000000000000000000;
            double le2 = ls2>0 ? nums2[ls2-1]:-1000000000000000000;
            double re1 = ls1<n ? nums1[ls1]:1000000000000000000;
            double re2 = ls2<m ? nums2[ls2]:1000000000000000000;
            if(le1<=re2 and le2<=re1) {
                if((m+n)%2==0) {
                    return (max(le1,le2) + min(re1,re2))/2.0;
                }
                return (double)max(le1,le2);
            } else if(le1 > re2) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return 0.0;
    }
};