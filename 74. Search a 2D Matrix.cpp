class Solution {
public:
    bool binarySearch(const vector<int>& ivec, int target)
    {
        auto positionIter = lower_bound(ivec.begin(), ivec.end(), target); 
        
        return positionIter != ivec.end() &&
                    (target == *positionIter) ? true : false; 
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> ivec;
        ivec.reserve(matrix.size());
        
        for (const auto& vec : matrix) {
            ivec.push_back(vec[0]);
        }
        
        auto positionIter = upper_bound(ivec.begin(), ivec.end(), target); 
        auto index = int(positionIter - ivec.begin()) - 1;
        
        if (index >= 0) {
            return binarySearch(matrix[index], target);
        }
 
        return false;
    }
};