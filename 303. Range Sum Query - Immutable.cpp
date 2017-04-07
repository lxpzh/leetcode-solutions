class NumArray {
public:
	NumArray(vector<int> &nums) {
 
        result.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			result.push_back(result.back() + nums[i]); 
		}
	}

	int sumRange(int i, int j) {
		return (result[j+1] - result[i]);
	}
private:
	vector<int> result;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);