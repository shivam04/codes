class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int prefix[n][m];
        memset(prefix,0,sizeof(prefix));
        for (int i = 0; i < n; i++) { 
		    for (int j = m - 1; j >= 0; j--) { 
                if (!mat[i][j]) 
                    continue; 
                if (j != m - 1) 
				    prefix[i][j] += prefix[i][j + 1]; 
                prefix[i][j] += mat[i][j]; 
		    } 
	    } 
        int ans = 0; 
        for (int j = 0; j < m; j++) { 
            int i = n - 1; 
            stack<pair<int, int> > q; 
            int to_sum = 0; 
            while(i>=0) {
                int c = 0; 
                while (q.size() != 0 and q.top().first > prefix[i][j]) {
                    to_sum -= (q.top().second + 1) * 
							(q.top().first - prefix[i][j]); 

				    c += q.top().second + 1; 
				    q.pop();
                }
                to_sum += prefix[i][j]; 
                ans += to_sum; 
                q.push({ prefix[i][j], c }); 
                i--;
            }
        }
        return ans;
    }
};