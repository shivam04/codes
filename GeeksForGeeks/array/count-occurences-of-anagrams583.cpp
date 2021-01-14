class Solution{
public:
    int allZero(int mp[]) {
        for(int i=0;i<26;i++) {
            if(mp[i]!=0)
                return false;
        }
        return true;
    }
	int search(string pat, string text) {
	    int N = text.length();
	    int n = pat.length();
	    
	    int mp[26];
	    memset(mp, 0, sizeof(mp));
	    for(int i=0;i<n;i++) {
	        mp[pat[i]-97]++;
	    }
	    for(int i=0;i<n;i++) {
	        mp[text[i]-97]--;
	    }
	    int res = 0;
	    if(allZero(mp)) {
	        res++;
	    }
	    for(int i=n;i<N;i++) {
	        mp[text[i]-97]--;
	        mp[text[i-n]-97]++;
	        if(allZero(mp)) {
	            res++;
	        }
	    }
	    return res;
	}

};