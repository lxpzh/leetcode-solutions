class Solution {
public:
    int majorityElement(vector<int> numbers) {
   		unordered_map<int, int> m;
        auto halfSize = numbers.size() / 2 + 1;
        
        for (auto i=0; i < numbers.size(); i++) {
 
            if (++m[numbers[i]] >=  halfSize) {
                return numbers[i];
            }
        }
        
        return 0;
    }
};