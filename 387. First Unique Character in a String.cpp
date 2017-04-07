class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> chVec(128, 0);
        
        for (auto const& ch : s) {
            chVec[ch]++;
        }
        
        for (string::size_type i = 0; i != s.size(); i++) {
            if (chVec[ s[i] ] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};