class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == 0) {
                auto temp = iter + 1;
                m.erase(iter);
            }
        }
    }
    
};