class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valNumber = 0;
        
        for (int i=0,j = nums.size()-1; i <= j;) {
            if (nums[i] == val) {
                if (nums[j] == val) {
                    --j;
                } else {
                    swap(nums[i], nums[j]);
                    ++i;
                    --j;
                }
                ++valNumber;
            } else {
                ++i;
            }
        }
        
        return (nums.size() - valNumber);
    }
};