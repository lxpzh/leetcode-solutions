class Solution {
public:
  /*  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for (size_t i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            } 
            else if (nums1[i] < nums2[j]) {
                ++i;
            }
            else {
                ++j;
            }
        }
        
        return result;
    }
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for (auto num : nums1) {
            auto iter = m.find(num);
            if (iter == m.end()) {
                m.insert({num, 1});
            }
            else {
                ++iter->second;
            }
        }
        
        for (auto num : nums2) {
            auto iter = m.find(num);
            if (iter != m.end()) {
                result.push_back(num);
                if (--iter->second == 0) {
                    m.erase(iter);   
                }
            }
        }
        
        return result;
    }
};