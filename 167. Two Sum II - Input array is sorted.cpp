class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        
        int first = 0;
        int last = numbers.size() - 1;
        
        while (first < last) {
            auto sum = numbers[first] + numbers[last];
            
            if (sum == target) {
                return vector<int>{first + 1, last + 1};
            }
            else if (sum < target) {
                ++first;
            } 
            else {
                --last;    
            }
        }
        return result;
    }
};