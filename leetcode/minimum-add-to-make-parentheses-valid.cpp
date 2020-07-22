class Solution {
public:
    int minAddToMakeValid(string S) {
        int bal = 0;
        int ans = 0;
        for (int i = 0; i < S.length(); ++i) { 
            bal += S[i] == '(' ? 1 : -1;
            if (bal == -1) { 
                ans += 1; 
                bal += 1; 
            } 
        }
        return ans+ bal;
    }
};