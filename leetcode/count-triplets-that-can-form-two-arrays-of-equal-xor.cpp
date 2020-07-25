//sol1 O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0; 
        int n = arr.size();
        vector<int> xors(n + 1);
        for (int i = 0; i < n; ++i) {
            xors[i + 1] = xors[i] ^ arr[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    int a = xors[j] ^ xors[i];
                    int b = xors[k+1] ^ xors[j];
                    if(a==b) 
                        ans++;
                }
            }
        }
        return ans;
    }
};


//sol2 O(n^2)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0; 
        int n = arr.size();
        vector<int> xors(n + 1);
        for (int i = 0; i < n; ++i)
            xors[i + 1] = xors[i] ^ arr[i];
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (xors[k + 1] == xors[i]) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }
};


//sol3 O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0; 
        int n = arr.size();
        unordered_map<int, int> freq{{0, 1}};    
        unordered_map<int, int> sum;
        int X = 0;
        for (int i = 0; i < n; ++i) {
          X ^= arr[i];
          ans += freq[X] * i - sum[X];
          ++freq[X];
          sum[X] += i + 1;
        }
        return ans;
    }
};