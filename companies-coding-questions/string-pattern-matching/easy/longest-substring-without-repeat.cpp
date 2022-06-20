int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int> mp;
    int start = 0;
    int i = 0;
	int n = A.size();
    int maxL = 1;
    while(i<n) {
        if(mp.find(A[i]) != mp.end()) {
            start = max(start, mp[A[i]] + 1);
        }
        mp[A[i]] = i;
        if(maxL < i-start + 1) {
            maxL = i - start + 1;
        }
        i++;
    }
    return maxL;
}
