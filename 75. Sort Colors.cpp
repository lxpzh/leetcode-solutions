class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        /* method 1
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        for (auto &num : nums) {
            num = q.top();
            q.pop();
        }
        */
        
        vector<int> ivec(3, 0);
        for (auto& num : nums) {
            ++ivec[num];
        }
        
        for (int i = 0, j = 0; i < ivec.size(); i++) {
            while (ivec[i]-- != 0) {
                nums[j++] = i;
            }
        }
    }
};