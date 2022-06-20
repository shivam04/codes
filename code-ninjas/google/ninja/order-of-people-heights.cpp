//O(N^2) 
//O(nlogn) exists
#include<bits/stdc++.h>
vector<int> findOrder(vector<int> & height, vector<int> & infront) {
    vector<pair<int,int>> A;
    int n = height.size();
    for(int i=0;i<n;i++) {
        A.push_back({height[i], infront[i]});
    }
    sort(A.begin(), A.end(), [](pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    });
    vector<int> ans(n), place(n);
    for(int i=0;i<n;i++) {
        place[i] = i;
    }
    for(int i=0;i<n;i++) {
        int p = A[i].second;
        for(int j=0;j<n;j++) {
            if(place[j] !=-1 and place[j]==p) {
                ans[j] = A[i].first;
                place[j]-=1;
                for(int k=j+1;k<n;k++) {
                    place[k]--;
                }
                break;
            }
        }
    }
    return ans;
}