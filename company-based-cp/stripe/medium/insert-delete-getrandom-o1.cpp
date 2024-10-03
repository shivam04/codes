class RandomizedSet {
public:
    vector<int> l;
    unordered_map<int, int> s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        }
        l.push_back(val);
        s[val] = l.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) {
            return false;
        }
        int idx = s[val];
        int lastItem = l.back();
        l[idx] = lastItem;
        s[lastItem] = idx;
        s.erase(val);
        l.pop_back();
        return true;
    }
    
    int getRandom() {
       int n = l.size();
       int rIdx = rand()%n;
       return l[rIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */