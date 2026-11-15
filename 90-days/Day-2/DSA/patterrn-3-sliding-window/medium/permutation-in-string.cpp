class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if (m >  n) {
            return 0;
        }
        int count = 0, sum=0;
        unordered_map<char, int> st, sst;

        for(int i=0;i<m;i++) {
            st[s1[i]]++;
        }
        for(int i=0;i<m;i++) {
            sst[s2[i]]++;
        }

        for (auto it: st) {
            if (it.second != sst[it.first]) {
                sum=1;
                break;
            }
        }

        if(sum==0) {
            count++;
        }
        

        for(int i=m;i<n;i++) {
            sum=0;
            sst[s2[i-m]]--;
            sst[s2[i]]++;
            for (auto it: st) {
                if (it.second != sst[it.first]) {
                    sum=1;
                    break;
                }
            }

            if(sum==0) {
                count++;
            }
        }

        return count>0;

    }
};