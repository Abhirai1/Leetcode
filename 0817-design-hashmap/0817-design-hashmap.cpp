class MyHashMap {
public:
    vector<list<pair<int,int>>> ans;
    int n;
    MyHashMap() {
        n=1000; 
        ans.resize(n);
    }
    
    int hash(int key){
        return key%n;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int i=hash(key);
        list<pair<int,int>> :: iterator it = ans[i].begin();
        while(it!=ans[i].end()){
            if(it->first==key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i=hash(key); 
        remove(key); 
        ans[i].push_back({key,value});
    }
    
    int get(int key) {
        int i=hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it==ans[i].end()) return -1;
        else return it->second;
        
    }
    
    void remove(int key) {
        int i=hash(key); 
        list<pair<int,int>> :: iterator it = search(key);
        if(it!=ans[i].end()) ans[i].erase(it);
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */