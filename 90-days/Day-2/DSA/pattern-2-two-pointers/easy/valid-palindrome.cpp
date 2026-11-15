class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int n=s.length()-1;

        while(i<n) {
            char a = tolower(s[i]);
            char b = tolower(s[n]);
            if (!isalnum(a)) {
                i++;
                continue;
            }
            if (!isalnum(b)) {
                n--;
                continue;
            }

            if(a==b) {
                i++;
                n--;
            }

            if(a!=b) {
                return false;
            }
        }
        return true;
    }
};