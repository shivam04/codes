vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> mp;
    sort(A.begin(),A.end());
    int i = 0;
    int k = 2;
    for(int n:A) {
        mp[n]=B.size()+k++;
    }
    for(int n:B) {
        mp[n]=i++;
    }
    sort(A.begin(), A.end(), [&mp](int a, int b) {
        return mp[a] < mp[b];
    });
    return A; 
}