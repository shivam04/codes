class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.length();
        int maxL = 1;
        int start = 0;
        for(int i=0;i<n;i++) {
            int low = i-1;
            int high = i+1;
            while(low>=0 and S[low]==S[i]) {
                low--;
            }
            while(high<n and S[high]==S[i]) {
                high++;
            }
            while(low>=0 and high<n and S[low]==S[high]) {
                low--;
                high++;
            }
            if(maxL < high-low-1) {
                maxL = high-low-1;
                start = low+1;
            }
        }
        return S.substr(start, maxL); 
    }
};