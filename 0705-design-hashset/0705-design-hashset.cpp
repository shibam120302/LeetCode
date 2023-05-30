class MyHashSet {
//Find a prime p=30011
public:
    const int p=30011;
    vector<list<int>> table;
    MyHashSet() {
        table.resize(p);
    }
    
    void add(int key) {
        int i=key%p;
        for(int& x: table[i])
            if(x==key) return ;
        table[i].emplace_back(key);
    }
    
    void remove(int key) {
        int i= key%p;
        for (auto it=table[i].begin(); it!= table[i].end(); it++) {
            if (*it == key) {
                table[i].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int i=key%p;
        for(int& x: table[i])
            if(x==key) return 1;
        return 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */