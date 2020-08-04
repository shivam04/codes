class Solution {
public:
    bool checkIfCanBreak(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n = a.size();
        bool flag = true;
        for(int i=0;i<n;i++) {
            if(a[i]<b[i]) {
                flag=false;
                break;
            }
        }
        if(flag)
            return flag;
        flag = true;
        for(int i=0;i<n;i++) {
            if(b[i]<a[i]) {
                flag=false;
                break;
            }
        }
        return flag;
    }
};