class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        vector<int> ivec(nums.size() + 1, 0);
        
        for (auto num : nums) {
            ++ivec[num];
        }
        
        for (size_t i = 1; i <= nums.size(); i++) {
            if (ivec[i] > 1) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};