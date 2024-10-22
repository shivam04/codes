class RandomizedSet {
public:
    vector<int> l;
    unordered_map<int, int> mp;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        l.push_back(val);
        mp[val] = l.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int idx = mp[val];
        int lastVal = l.back();
        l[idx] = lastVal;
        mp[lastVal] = idx;
        l.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = l.size();
       int idx = rand()%n;
        return l[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */