//O(N^3)
#include<bits/stdc++.h>
int sumZero(vector<int> A, int n) {
    int sum = 0;
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) {
        sum += A[i];
        if(sum == 0) {
            ans++;
        }
        if(mp.find(sum)!=mp.end()) {
            ans += (mp[sum]);
        }
        mp[sum]++;
    }
    return ans;
}
int subMatrices(vector<vector<int>> &mat, int n) {
    vector<int> temp(n);
    int ans = 0;
    for(int i=0;i<n;i++) {
        temp[i] = 0;
    }
    
    for(int k=0;k<n;k++) {
        for(int j=k;j<n;j++) {
            for(int i=0;i<n;i++) {
                temp[i] += mat[i][j];
            }
            
            ans += sumZero(temp, n);
        }
        for(int i=0;i<n;i++) {
            temp[i] = 0;
        }
    }
    
    return ans;
}
 

