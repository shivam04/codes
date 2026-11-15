class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = p.length();
        int n = s.length();
        int sum=0;
        vector<int> ans;
        if (m >  n) {
            return ans;
        }
        unordered_map<char, int> st, sst;
        for(int i=0;i<m;i++) {
            st[p[i]]++;
        }

        for(int i=0;i<m;i++) {
            sst[s[i]]++;
        }

        for (auto it: st) {
            if (it.second != sst[it.first]) {
                sum=1;
                break;
            }
        }

         if(sum==0) {
            ans.push_back(0);
        }

        for(int i=m;i<n;i++) {
            sum=0;
            sst[s[i-m]]--;
            sst[s[i]]++;
            for (auto it: st) {
                if (it.second != sst[it.first]) {
                    sum=1;
                    break;
                }
            }

            if(sum==0) {
                ans.push_back(i-m+1);
            }
        }

        return ans;

    }
};