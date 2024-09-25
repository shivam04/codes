class LRUCache {
public:
    list<pair<int,int>> dq;
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    int csize;
    LRUCache(int capacity) {
        csize = capacity;
        cache.clear();
        dq.clear();
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        int val = cache[key]->second;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            dq.erase(cache[key]);
        } else {
            if (dq.size() == csize) {
                auto lastEle = dq.back();
                dq.pop_back();
                cache.erase(lastEle.first);
            }
        }
        dq.push_front({key,value});
        cache[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */