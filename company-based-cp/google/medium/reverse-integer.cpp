class Solution {
public:
    int mini = -2147483648;
    int maxi = 2147483647;
    int reverse(int x) {
        int isNeg = x < 0;
        x = abs(x);
        long y = 0;
        while(x) {
            long w = x%10;
            y = y*10 + w;
            x/=10;
        }
       long s = isNeg ? -1*y : y;
       return (mini<=s and s<=maxi) ? (int)s : 0;
    }
};