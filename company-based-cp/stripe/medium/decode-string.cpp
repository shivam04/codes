class Solution {
public:
    pair<int, string> multiplyStr(string s, int x) {
        int num = 0;
        
        while(isdigit(s[x])) {
            num = num*10 + (s[x]-48);
            x++;
        }

        string p = "";
        int c = 1;
        int j;

        for (j=x+1;c>0;j++) {
            p = p + s[j];
            if (s[j] == '[') {
                c++;
            }
            if (s[j] == ']') {
                c--;
            }
        }

        p.pop_back();
        j--;
        string pStr = "";
        for (int i=0;i<p.length();i++) {
            if (isdigit(p[i])) {
                auto pi = multiplyStr(p, i);
                i = pi.first;
                pStr += pi.second;
            } else {
                pStr += p[i];
            }
        }
        string newStr = "";
        for (int i=0;i<num;i++) {
            newStr = newStr + pStr;
        }
        return {j, newStr};
    }
    string decodeString(string s) {
        string ans = "";
        for (int i=0;i<s.length();i++) {
            if (isdigit(s[i])) {
                auto p = multiplyStr(s, i);
                i = p.first;
                ans += p.second;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};