class Solution {
public:
    int maxHist(vector<int> arr, int n) {
        stack<int> s;
        int ti;
        int maxR = 0;
        int i = 0;
        while(i<n) {
            if(s.empty() || arr[s.top()] <= arr[i]) {
                s.push(i++);
                continue;
            }
            ti = s.top();
            s.pop();
            int r = arr[ti]*(s.empty()?i:i-s.top()-1);
            maxR = max(maxR, r);
        }
        while(!s.empty()) {
            ti = s.top();
            s.pop();
            int r = arr[ti]*(s.empty()?i:i-s.top()-1);
            maxR = max(maxR, r);
        }
        return maxR;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp;
        for(int i=0;i<m;i++) {
            temp.push_back(matrix[0][i]-48);
        }
        int result = maxHist(temp, m);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j]=='1')
                    temp[j]+=(matrix[i][j]-48);
                else
                    temp[j] = 0;
            }
            result = max(result, maxHist(temp, m));
        }
        return result;
    }
};