//sol1 O(sqrt(n) + plogp)
// p-> no. of factors of n
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=sqrt(n); i++) {
            if(n%i==0) {
                int p = n/i;
                if(p!=i) {
                    ans.push_back(i);
                    ans.push_back(p);
                } else {
                    ans.push_back(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size()==0 || ans.size() < k)
            return -1;
        return ans[k-1];
    }
};


//sol2 O(min(n,k))
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) factors.push_back(i);
            if (factors.size() == k) return factors[k - 1];
        }
        return -1;
    }
};