class MyHashSet {
public:
    int m;
    vector<list<int>> buckets;

    int getIndex(int key){
        return key%m;
    }

    MyHashSet() {
        m = 15000;
        buckets = vector<list<int>> (m, list<int>{});
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        if(it == buckets[index].end()) buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        if(it != buckets[index].end()) buckets[index].erase(it);
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        return it != buckets[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */