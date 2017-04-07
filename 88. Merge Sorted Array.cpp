class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        
        int i, j;
        for (i = 0, j = 0; i < m && j < n; ) {
            if (nums1[i] <= nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        if (i == m && j < n) {
            copy(nums2.begin() + j, nums2.begin() + n, back_inserter(result));
        } 
        if (j == n && i < m) {
            copy(nums1.begin() + i, nums1.begin() + m, back_inserter(result));
        }
        
        nums1.swap(result);
    }
};