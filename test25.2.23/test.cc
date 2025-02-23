class Trie {
    public:
        Trie() {
                    
        }
        
        void insert(string word) {
            size_t next = 0;
            for(auto e : word)
            {
                trie.push_back(vector<int>(26,0));
                char c = e - 'a';
                if(trie[next][c] == 0) trie[next][c] = trie.size();
                next = trie[next][c];
            }
            if(count.size() < next+1) count.resize(next+1,0);
            count[next]++;
        }
        
        bool search(string word) {
            size_t next = 0;
            for(auto e : word)
            {
                if(trie.size() <= next) return false;
                next = trie[next][e-'a'];
                if(!next) return false;
            }
            if(count[next] > 0) return true;
            else return false;
        }
        
        bool startsWith(string prefix) {
            size_t next = 0;
            for(auto e : prefix)
            {
                if(trie.size() <= next) return false;
                next = trie[next][e-'a'];
                if(!next) return false;
            }
            return true;
        }
        vector<vector<int>> trie;
        vector<int> count;
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */