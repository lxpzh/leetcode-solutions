class Solution {
public:
 bool nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return false;
        auto it = nums.rbegin();
        for (++it; it != nums.rend() ; ++it) {
              if (*(it - 1) > *it) {
                  break;
              }
        }
        auto iter = it.base();
 
        if (iter == nums.begin()) {
            return false;
        } else {
            auto preIter = iter - 1;

            for (auto tempIter = nums.end() - 1; tempIter != preIter; --tempIter) {
                if (*tempIter > *preIter) {
                    swap(*tempIter,*preIter);
                    reverse(iter,nums.end());
                    return true;
                }
            }
            return false;
        }
    }
 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ivec;
        
        do {
            ivec.push_back(nums); 
           } while (nextPermutation(nums));
         
        return ivec;
    }
};