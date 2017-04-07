class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;
        auto it = nums.rbegin();
        for (++it; it != nums.rend() ; ++it) {
              if (*(it - 1) > *it) {
                  break;
              }
        }
        auto iter = it.base();
 
        if (iter == nums.begin()) {
            reverse(nums.begin(), nums.end());
        } else {
            auto preIter = iter - 1;

            for (auto tempIter = nums.end() - 1; tempIter != preIter; --tempIter) {
                if (*tempIter > *preIter) {
                    swap(*tempIter,*preIter);
                     reverse(iter,nums.end());
                    break;
                }
            }
        }
    }
};
