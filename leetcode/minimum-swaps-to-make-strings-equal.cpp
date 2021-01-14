class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.length();
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) { 
            if(s1[i] == 'x' and s2[i] == 'y')
                c1++;
            if(s1[i] == 'y' and s2[i] == 'x')
                c2++;
        }
        int ans = c1/2 + c2/2;
        if (c1 % 2 == 0 && c2 % 2 == 0) { 
            return ans; 
        } 
        else if ((c1 + c2) % 2 == 0) { 
            return ans + 2; 
        }
        return -1;
    }
};