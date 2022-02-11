class Solution {
public:
    vector<string> split(string s, char c) {
        vector<string> ans;
        string p = "";
        for(char ch: s) {
            if(ch==c || ch=='i') {
                ans.push_back(p);
                p = "";
                continue;
            }
            p += ch;
        }
        return ans;
    }
    string complexNumberMultiply(string num1, string num2) {
        vector<string> x = split(num1, '+');
        vector<string> y = split(num2, '+');
        int a_real = stoi(x[0]);
        int a_img = stoi(x[1]);
        int b_real = stoi(y[0]);
        int b_img = stoi(y[1]);
        return to_string(a_real * b_real - a_img * b_img) + "+" + to_string(a_real * b_img + a_img * b_real) + "i";
    }
};