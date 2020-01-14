vector<int> Solution::equal(vector<int> &A) {
    vector<int> ans;
    vector<int> all_ans;
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            int sum = A[i]+A[j];
            if(mp.find(sum)==mp.end()){
                mp[sum].push_back(i);
                mp[sum].push_back(j);
            }else{
                int flag = 0;
                ans.push_back(mp[sum][0]);
                ans.push_back(mp[sum][1]);
                ans.push_back(i);
                ans.push_back(j);
                for(int x=0;x<4;x++){
                    for(int y=x+1;y<4;y++){
                        if(ans[x]==ans[y]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag)
                    break;
                }
                //cout<<flag<<"\n";
                if(flag){
                    ans.clear();
                    continue;
                }
                if(all_ans.size()==0){
                    //cout<<"K\n";
                    all_ans = ans;
                }
                else{
                    for(int z=0;z<ans.size();z++){
                        if(ans[z]<all_ans[z]){
                            all_ans = ans;
                        }else if(all_ans[z]<ans[z]){
                            break;
                        }
                    }
                }
                ans.clear();
            }
        }
    }
    return all_ans;
}