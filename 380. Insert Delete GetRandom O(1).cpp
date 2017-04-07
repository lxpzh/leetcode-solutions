class RandomizedSet {
private:
    unordered_map<int, int> m;
    vector<int> ivec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(unsigned(time(0)));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter = m.find(val);
        
        if (iter == m.end()) {
            m.insert({val, ivec.size()});
            ivec.push_back(val);
            return true;
        } 
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = m.find(val) ;
        
        if (iter != m.end()) {
            auto index = iter->second;
            ivec[index] = ivec[ivec.size() - 1];
            if ( !ivec.empty() ) {
                ivec.pop_back();
            }
            m[ivec[index]] = index;
            m.erase(iter);
            return true;
        } 
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
       auto randNumIndex = rand() % ivec.size();
       return ivec[randNumIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */