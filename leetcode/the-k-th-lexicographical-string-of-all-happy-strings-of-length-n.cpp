#include<bits/stdc++.h>
class Solution {
public:
    string getHappyString(int n, int k) {
        char a[3] = {'a', 'b', 'c'};
        vector<string> s;
        s.push_back("a");
        s.push_back("b");
        s.push_back("c");
        for(int i=1;i<n;i++) {
            vector<string> more;
            for(string x: s) {
                for(int j=0;j<3;j++) {
                    if(x[i-1] != a[j]) {
                        more.push_back(x+a[j]);
                    }
                } 
            }
            s = more;
        }
        if(s.size()<k)
            return "";
        return s[k-1];
    }
};