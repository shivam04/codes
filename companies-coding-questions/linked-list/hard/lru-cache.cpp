struct Node {
    int val;
    int key;
    Node *next,*prev;
    Node(int x, int k) {
        val = x;
        key = k;
        next = prev = nullptr;
    }
};
int fullCapacity;
unordered_map<int, Node*> mp;
Node *head = new Node(-1, -1); 
Node *rear = new Node(-1, -1);
LRUCache::LRUCache(int capacity) {
    fullCapacity =  capacity;
    head = new Node(-1, -1); 
    rear = new Node(-1, -1);
    head->next = rear;
    rear->prev = head;
    mp.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)!=mp.end()) {
        Node* res = mp[key];
        int ans = res->val;
        set(res->key, res->val);
        return ans;
    }
    return -1;
}
void addNode(Node* head, Node* temp) {
    temp->next = head->next;
    temp->prev = head;
    head->next->prev = temp;
    head->next = temp;
}
void deleteNode(Node* temp) {
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete(temp);
}
void LRUCache::set(int key, int value) {
    if(mp.find(key) != mp.end()) {
        Node* temp = mp[key];
        mp.erase(key);
        deleteNode(temp);
    }
    if(mp.size()==fullCapacity) {
        Node* temp = rear->prev;
        mp.erase(temp->key);
        deleteNode(temp);
    }
    addNode(head, new Node(value, key));
    mp[key] = head->next;
}
