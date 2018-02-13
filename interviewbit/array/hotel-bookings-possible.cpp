bool comp(pair<int, int> j, pair<int, int> i){
    if(i.first > j.first){
        return true;
    }
    else if(i.first == j.first){
        if(i.second > j.second){
            return true;
        }
    }
    return false;
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int arr = 0;
    int dep = 0;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    while(arr < arrive.size()){
        K--;
        arr++;
        if(K == 0){
            if(arrive[arr] >= depart[dep]){
                K++;
                dep++;
            }    
        }
        if(K < 0){
            return false;
        }
    }

    
    return true;
}
