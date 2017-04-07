class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto const& num : nums) {
            result ^= num;
        }
        
        return result;
    }
};