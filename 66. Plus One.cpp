class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        result.reserve(digits.size());
        int end = digits.size() - 1;
        int flag = 0;
        
        if (digits[end] + 1 >= 10) {
            result.push_back(digits[end--] + 1 - 10);
            flag = 1;
        }
        while (end >= 0 && digits[end] + flag >= 10) {
            result.push_back(digits[end] + flag - 10);
            end--;
        }
         
        if (end < 0 && flag) {
            result.push_back(flag);
        } else if (end >= 0) {
            result.push_back(digits[end] + 1);
            for (--end ;end >= 0; end--) {
                result.push_back(digits[end]);
            }
        }
    
        reverse(result.begin(), result.end());
        return result;
    }
};