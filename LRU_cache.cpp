/*
	We are given total possible page numbers that can be referred. 
	We are also given cache size. The LRU caching scheme is to 
	remove the least recently used frame when the cache 
	is full and a new page is referenced which is not there in cache. 
*/


class LRUCache {
private:
    int capacity;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> pos;
    
    void use(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= capacity) {
            int old = recent.back();
            recent.pop_back();
            cache.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
    
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            use(key);
            return cache[key];
        }
        return -1;
    }
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

