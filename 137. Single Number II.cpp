class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
         
        for (auto const& num : nums) {
            auto pos = m.insert({num, 0});
            ((pos.first)->second)++;
        }
        
        for (auto const& num : nums) {
            if (m[num] == 1) {
                return num;
            }
        }
        
        return 0;
    }
};