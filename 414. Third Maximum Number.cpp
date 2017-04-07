class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.empty())
            return -1;
            
        priority_queue<int> q(nums.begin(), nums.end());
        int result ;
        int max = q.top();
        int distinctNum = 0;
        
        while ( distinctNum < 3 && !q.empty() ) {
            do {
                result = q.top();
                q.pop();
            } while (!q.empty() && q.top() == result);
            ++distinctNum;
        }
        
        return distinctNum == 3 ? result : max;
    }
};