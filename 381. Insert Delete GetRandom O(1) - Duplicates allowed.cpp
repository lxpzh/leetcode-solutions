class RandomizedCollection {
private:
    unordered_multimap<int, int> valueIndexMap;
    vector<int> ivec;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(unsigned(time(0)));
    }
    
    void displayVec(const vector<int>& vec) {
        for(auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    void displayMap() {
        for (auto const& p : valueIndexMap) {
            cout << p.first << " : " << p.second << endl;;
        }
        cout << endl;
    }
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto pos = valueIndexMap.equal_range(val);
        ivec.push_back(val);
        valueIndexMap.insert({val,  ivec.size() - 1});
 
        return pos.first == pos.second;    // can't find val, return true
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto pos = valueIndexMap.equal_range(val);
        if (pos.first != pos.second) {
            int index = pos.first->second;
            int lastIndex = ivec.size() - 1;
            
            if (index != lastIndex) {
                ivec[index] = ivec[lastIndex];  // swap with last val;
                
                auto lastValPos = valueIndexMap.equal_range(ivec[lastIndex]);   // 
                while (lastValPos.first != lastValPos.second) {
                    if (lastValPos.first->second == lastIndex) {
                        lastValPos.first->second = index;
                        break;
                    }
                    ++lastValPos.first;
                }
            }
            valueIndexMap.erase(pos.first);
            ivec.pop_back();
          
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % ivec.size();
        return ivec[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */