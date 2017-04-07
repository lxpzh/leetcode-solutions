class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = -1;
  
        auto lowIter = lower_bound(nums.begin(), nums.end(), target);
        if (lowIter != nums.end() && *lowIter == target) {
            low = ptrdiff_t(lowIter - nums.begin());
        }
         
        int high = low;
        while (nums[high] == target && high < nums.size()) {
            ++high;
        }
        if (low != -1) {
            high = high - 1;
        }
        return vector<int>{low, high };
    }
};