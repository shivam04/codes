int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s;
    for(int i=0;i<A.size();i++){
        s.insert(A[i]);
    }
    int ans = INT_MIN;
    for (int i=0; i<A.size(); i++)
    {
        if (s.find(A[i]-1) == s.end())
        {
            int j = A[i];
            while (s.find(j) != s.end())
                j++;
            ans = max(ans, j - A[i]);
        }
    }
    return ans;
}
