vector<int> createLPSArray(string a) {
	int n = a.length();
	vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while(i<n) {
        if(a[len]==a[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len>0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}