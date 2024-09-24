class LRUCache {
public:
    list<pair<int,int>> dq;
    int csize;
    unordered_map<int, list<pair<int,int>>::iterator> ma;

    LRUCache(int capacity) {
        csize = capacity;
    }
    
    int get(int key) {
        if (ma.find(key) == ma.end()) {
            return -1;
        }
        int value = ma[key]->second;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (ma.find(key) == ma.end()) {
            if (dq.size() == csize) {
                auto last = dq.back();
                dq.pop_back();
                ma.erase(last.first);
            }
        } else {
            dq.erase(ma[key]);
        }
        dq.push_front({key, value});
        ma[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */