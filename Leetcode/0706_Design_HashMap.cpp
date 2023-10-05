class MyHashMap {
public:
    int size;
    vector<list<pair<int, int>>> buckets;

    int getIndex(int key){
        return key%size;
    }

    MyHashMap() {
        size = 10000;
        buckets.resize(size);
    }
    
    void put(int key, int value) {
        int index = getIndex(key);
        auto &chain = buckets[index];
        for(auto &it : chain){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        chain.push_back({key, value});
    }
    
    int get(int key) {
        int index = getIndex(key);
        auto &chain = buckets[index];
        
        if(chain.empty()) return -1;

        for(auto &it : chain){
            if(it.first == key) return it.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto &chain = buckets[index];

        for(auto it = chain.begin(); it != chain.end(); it++){
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */