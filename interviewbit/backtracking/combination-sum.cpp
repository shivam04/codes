void findNumbers(vector<int>& ar, int sum,vector<vector<int> >& res,vector<int>& r, int i)
{
    if (sum < 0)
        return;
    if (sum == 0)
    {
        res.push_back(r);
        return;
    }
    while (i < ar.size() && sum - ar[i] >= 0)
    {
        r.push_back(ar[i]);
        findNumbers(ar, sum - ar[i], res, r, i);
        i++;
        r.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vector<int> > k;
    vector<int> p;
    findNumbers(A, B, k, p, 0);
    return k;
}