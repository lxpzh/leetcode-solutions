class Solution {
private:
    vector<int> ivec;
    vector<int> original;
    random_device rd;
public:
    Solution(vector<int> nums) {
        ivec = nums;
        original = nums;
        srand(unsigned(time(NULL)));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ivec = original;
        return ivec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto n = ivec.size();
        for (size_t i = 0; i < n; i++) {
            int index1 = rand() % (n - i);
            swap(ivec[i + index1], ivec[i]);
        }
        return ivec;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */