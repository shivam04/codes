class Solution {
public:
    long long countVowels(string word) {
        long long cnt = 0;
        long long n = word.length();
        for(long long i=0;i<word.length();i++) {
            if(string("aeiou").find(word[i]) != string::npos) {
                cnt += (i + 1) * (n - i);
            }
        }
        return cnt;
    }
};