string Solution::minWindow(string A, string B) {
    unordered_map<char,int> mpb,mpa;
    for(char b: B) {
        mpb[b]++;
    }

    int start = 0;
    int i = 0;
    int minLen = INT_MAX;
    int n = A.size();
    int si = -1;
    int cnt = 0;
    while(i<n) {
        mpa[A[i]]++;
        if(mpa[A[i]] <= mpb[A[i]]) {
            cnt++;
        }

        if(cnt==B.size()) {
            while(mpa[A[start]] > mpb[A[start]] || mpb[A[start]]==0) {
                if(mpa[A[start]] > mpb[A[start]])
                    mpa[A[start]]--;
                start++;
            }
            if(minLen > i-start+1) {
                minLen = i - start+1;
                si = start;
            }
        }
        i++;
    }
    if(si==-1)
        return "";
    return A.substr(si,minLen);
}