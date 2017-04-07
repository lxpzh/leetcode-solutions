class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         unordered_map<int, int> m;
         
        for (auto const& num : nums) {
            auto iter = m.find(num);
            if (iter == m.end()) {
                m.insert({num, 1});
            } else {
                ++iter->second;
            }
        }
        
        vector<int> result;
        for (auto const& num : nums) {
            if (m[num] == 1) {
                result.push_back(num);
            }
        }
         return result;
     
        
       return nums;
       
    }
};