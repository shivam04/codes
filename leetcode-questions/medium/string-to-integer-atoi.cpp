class Solution {
public:
    int mini = -2147483648;
    int maxi = 2147483647;
    string ltrim(const string &s) {
        int i = 0;
        while(i<s.length()) {
            if (s[i] != ' ')
                break;
            i++;
        }
        return s.substr(i);
    }
    string rtrim(const string &s) {
        int i = s.length()-1;
        while(i >= 0) {
            if (s[i]!= ' ')
                break;
            i--;
        }
        return s.substr(0, i+1);
    }
    string trim(const string &s) {
        return rtrim(ltrim(s));
    }
    string rtrimChar(string &s) {
        int i = s.length()-1;
        while(i >= 0) {
            if (s[i] >= '0' and s[i]<='9')
                break;
            i--;
        }
        return s.substr(0, i+1);
    }
    string getFirstNumbers(string &s) {
        int i = 0;
        while(i<s.length()) {
            if (s[i] < '0' || s[i] > '9')
                break;
            i++;
        }
        return s.substr(0, i);
    }

    string removeZeroes(string &s) {
        int i = 0;
        while(i<s.length()) {
            if (s[i] > '0' and s[i] <= '9')
                break;
            i++;
        }
        return s.substr(i);
    }
    int myAtoi(string s) {
        s = trim(s);
        s = rtrimChar(s);
        int isNeg = s[0] == '-';
        int isPos = s[0] == '+';
        if(isNeg || isPos) {
            s.erase(s.begin());
        }
        if ((s.length() == 0) || (s.length() > 1 and (s[0] < '0' || s[0] > '9'))) {
            return 0;
        }
        s = getFirstNumbers(s);
        s = removeZeroes(s);
        if (s.length() >= 11) {
            return isNeg ? mini : maxi;
        }

        long ans = 0;
        for(char a: s) {
            int p = a - 48;
            ans = ans*10 + (long)p;
        }
        long ss = isNeg ? -1*ans : ans;
        if (ss <= mini)
            return mini;
        if (ss >= maxi)
            return maxi;
        return ss;
    }
};