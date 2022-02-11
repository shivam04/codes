class Solution {
public:
    int getSubTreeSize(int s, vector<int> tree[], int subSize[]) {
        subSize[s] = 1;
        for(auto c: tree[s]) {
            subSize[s] += getSubTreeSize(c, tree, subSize);
        }
        return subSize[s];
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> tree[n];
        int subSize[n];
        for(int i=0;i<n;i++) {
            if(parents[i]!=-1)
            tree[parents[i]].push_back(i);
        }
        getSubTreeSize(0, tree, subSize);
        long long maxi = -1;
        long long cur = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            cur = max(n-subSize[i], 1);
            for(int c: tree[i]) {
                cur = cur*subSize[c];
            }
            if(cur > maxi) {
                maxi = cur;
                ans = 1;
            } else if(cur==maxi) ans++;
        }
        return ans;
    }
};