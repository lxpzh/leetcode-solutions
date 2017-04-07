class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_multimap<int, int> intMap;
        intMap.reserve(nums.size());
   
        for (size_t i=0; i < nums.size(); i++) {
            intMap.insert( {nums[i], i} );
        }
        
        for (auto i = 0; i < nums.size(); i++) {
            auto iterPair = intMap.equal_range(nums[i]);
            auto iterFirst = iterPair.first;
            auto iterSecond = iterPair.second;
            
            if (iterFirst != iterSecond) {
                auto preIter = iterFirst;
                auto tempIter = iterFirst;
                while (++iterFirst != iterSecond) {
                    if (abs(iterFirst->second - preIter->second) <= k) {
                        return true;
                    }
                    preIter = iterFirst;
                }
                if (++tempIter != iterSecond)
                    intMap.erase(nums[i]);      //删除重复元素，这样避免重复查找
            }
        }
        return false;
    }
};