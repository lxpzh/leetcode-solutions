class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) {
            return 0;
        }
        const int SIZE = 60;
        vector<char> ivec(SIZE, 0);
        for (char ch : s) {
            ++ivec[ch - 'A'];
        }
        
        int oddNum = 0;
        for (auto value : ivec) {
            if (value !=0 && (value & 1)) {
                ++oddNum;
            }
        }
     
        return (oddNum == 0) ? s.size() : (s.size() - oddNum + 1);
    }
};