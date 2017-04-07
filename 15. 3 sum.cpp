class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i=0 ; i <  nums.size(); i++)
        {
            int front = i + 1;
            int back = nums.size() - 1;
            int target = -nums[i];
            
            while (front < back)
            {
                int sum = nums[front] + nums[back] ;
                if (sum > target)
                {
                    --back;
                } 
                else if (sum < target) 
                {
                    ++front;
                }
                else 
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[front]);
                    temp.push_back(nums[back]);
                    result.push_back(temp);
                    
                    while (front < back && nums[front] == temp[1]) 
                    {
                        front++;
                    }
                    
                    while (front < back && nums[back] == temp[2]) 
                    {
                        --back;
                    }
                }
                while (i + 1 < nums.size() && nums[i] == nums[i+1]) 
                {
                    ++i;
                }
            }
            
        }
         
        return result;
    }
};class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string();
        }
        
        auto minStrIter = min_element(strs.begin(), strs.end(), 
            [](const string& str1, const string& str2) {
                return str1.size() < str2.size();
        });
        
        auto minStr = *minStrIter;
 
        int prefixLen = minStr.size();
        for (const auto& str : strs) {
            
            int i;
            for (i = 0; i < minStr.size(); i++) {
                if (minStr[i] != str[i]) {
                    break;
                }
            }
            
            if (i < prefixLen) {
                prefixLen = i;
            }
        }
        
        return minStr.substr(0, prefixLen);
    }
};