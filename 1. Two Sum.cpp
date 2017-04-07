class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> m;
       vector<int> result;
       
       for (auto i = 0; i < nums.size(); i++) {
           m.insert({nums[i], i});
       }
       
       for (auto i = 0; i < nums.size(); i++) {
           auto iter = m.find(target - nums[i]);
           
           if (iter != m.end() && iter->second != i) {
               result.push_back(i);
               result.push_back(iter->second);
               return result;
           }
       }
       
       return result;
    }
};