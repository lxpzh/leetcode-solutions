class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        
        int dumpNumber = 0;
        
        for (int i=0,j = 1; i < nums.size() && j < nums.size(); ++j) {
            if (nums[i] != nums[j]) { 
                nums[++i] = nums[j];
            } else {
                ++dumpNumber;
            }
        }
        
        return (nums.size() - dumpNumber);
    }
};