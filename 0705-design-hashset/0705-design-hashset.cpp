class MyHashSet {
public:
    vector<list<int>> ans; 
    int n;
    MyHashSet() {
        n=100;
        ans.resize(n);
    } 
    
    int hash(int key){
        return key%n;
    }
    
    list<int> :: iterator search(int key){
        int i=hash(key); 
        return find(ans[i].begin(),ans[i].end(),key);
    }
    
    void add(int key) {
        if((contains(key))) return; 
        int i=hash(key); 
        ans[i].push_back(key);
    }
    
    void remove(int key) {
        if(!(contains(key))) return; 
        int i=hash(key); 
        ans[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key); 
        if(search(key)!=ans[i].end())
            return true; 
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */