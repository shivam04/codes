#define f first
#define s second
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<pair<int,pair<int,int> > > Aux;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            Aux.push_back({A[i]+A[j],{i,j}});
        }
    }
    vector<vector<int> > ans;
    unordered_map<int,vector<int> > mp;
    for(int i=0;i<Aux.size();i++){
        int diff = B - Aux[i].first;
        if(mp.find(diff)!=mp.end()){
            for(int k=0;k<mp[diff].size();k++){
                int j = mp[diff][k]-1;
                if(Aux[j].s.f!=Aux[i].s.f and Aux[j].s.s!=Aux[i].s.s and Aux[j].s.f!=Aux[i].s.s and Aux[j].s.s!=Aux[i].s.f){
                    vector<int> one_ans;
                    one_ans.push_back(A[Aux[j].second.first]);
                    one_ans.push_back(A[Aux[j].second.second]);
                    one_ans.push_back(A[Aux[i].second.first]);
                    one_ans.push_back(A[Aux[i].second.second]);
                    sort(one_ans.begin(),one_ans.end());
                    if(find(ans.begin(),ans.end(),one_ans)==ans.end())
                    ans.push_back(one_ans);
                }
            }
        }
        mp[Aux[i].first].push_back(i+1);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
