class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {
        
    }
    int get(int key) {
        auto it = hash.find(key);
        if(it == hash.end()) return -1;
        lt.push_front(*(it->second));
        lt.erase(it->second);
        hash[key] = lt.begin();
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        lt.push_front({key,value});
        if(it == hash.end())
        {
            hash[key] = lt.begin();
            if(lt.size() > cap)
            {
                hash.erase(lt.back().first);
                lt.pop_back();
            }
        }
        else{
            lt.erase(it->second);
            hash[key] = lt.begin();
        }
    }
    unordered_map<int,list<pair<int,int>>::iterator> hash;
    list<pair<int,int>> lt;
    int cap;
};