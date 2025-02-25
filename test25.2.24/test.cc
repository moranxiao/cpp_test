class Trie {
    vector<Trie*> children;
    bool isExist;
public:
    Trie() 
    :children(26,nullptr),
    isExist(false)
    {
    
    }
    
    void insert(string word) {
        Trie* trie = this;
        for(auto e : word)
        {
            if(trie->children[e-'a'] == nullptr)
            {
                trie->children[e-'a'] = new Trie;
            }
            trie = trie->children[e-'a'];
        }
        trie->isExist = true;
    }
    
    bool search(string word) {
        Trie* trie = this;
        for(auto e : word)
        {
            if(trie->children[e-'a'] == nullptr)
                return false;
            trie = trie->children[e-'a'];
        }
        return trie->isExist;
    }
    
    bool startsWith(string prefix) {
        Trie* trie = this;
        for(auto e : prefix)
        {
            if(trie->children[e-'a'] == nullptr)
                return false;
            trie = trie->children[e-'a'];
        }
        return true;
    }
};
