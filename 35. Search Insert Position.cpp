class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) {
            return 0;
        } 
            
        auto iter = lower_bound(nums.begin(), nums.end(), target);
        if (iter != nums.end() && *iter == target) {
            return iter - nums.begin();
        } else {
            return (iter - nums.begin()) ; 
        }
    }
};