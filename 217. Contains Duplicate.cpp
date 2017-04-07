class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (auto const& num : nums) {
            if (s.find(num) == s.end()) {
                s.insert(num);
            } 
            else {
                return true;
            }
        }
        return  false;
    }
};