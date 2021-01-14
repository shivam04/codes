class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        reverse(digits.begin(), digits.end());
        int sum = accumulate(digits.begin(), digits.end(), 0); 
        int n = digits.size();
        string ans = "";
        if(sum%3==0) {
               for(auto i : digits) {
                   ans = ans + (char)(i + 48);
               }
        }
        int rem = sum%3;
        int i;
        if(rem == 1) {
            int rem2[2];
            int flag = 0;
            rem2[0] = -1, rem2[1] = -1;
            for(i=n-1;i>=0;i--) {
                if(digits[i]%3==1) {
                    flag = 1;
                    break;
                } else if(digits[i]%3==2) {
                    if(rem2[0] == -1)
                        rem2[0] = i;
                    if(rem2[1] == -1) {
                        flag = 2;
                        rem2[1] = i;
                    }
                }
            }
            if(flag==1) {
                for(int j=0;j<n;j++) {
                    if(j != i) {
                        ans = ans + (char)(digits[j] + 48);
                    }
                }
            } else if(flag==2) {
                for(int j=0;j<n;j++) {
                    if(j != rem2[0] && j != rem2[1]) {
                        ans = ans + (char)(digits[j] + 48);
                    }
                }
            }
        } else if(rem == 2) {
            int rem1[2];
            int flag = 0;
            rem1[0] = -1, rem1[1] = -1;
            for(i=n-1;i>=0;i--) {
                if(digits[i]%3==2) {
                    flag = 2;
                    break;
                } else if(digits[i]%3==1) {
                    if(rem1[0] == -1)
                        rem1[0] = i;
                    if(rem1[1] == -1) {
                        flag = 1;
                        rem1[1] = i;
                    }
                }
            }
            if(flag==2) {
                for(int j=0;j<n;j++) {
                    if(j != i) {
                        ans = ans + (char)(digits[j] + 48);
                    }
                }
            } else if(flag==1) {
                for(int j=0;j<n;j++) {
                    if(j != rem1[0] && j != rem1[1]) {
                        ans = ans + (char)(digits[j] + 48);
                    }
                }
            }
        }
        int allZero = 0;
        for(int i=0;i<ans.length();i++) {
            if(ans[i]=='0')
                allZero++;
        }
        if(allZero == ans.length() and ans != "") {
            return "0";
        }
        return ans;
    }
};